#!/bin/bash
# Kullanım:
#   ./push.sh <modul_klasoru> "<commit mesaji>" [intra_repo_url]
#
# Örnek (ilk sefer, intra URL'si kaydedilir):
#   ./push.sh cpp02 "ex00 bitti" git@vogsphere.42kocaeli.com.tr:vogsphere/intra-uuid-xxxx
# Sonraki seferler:
#   ./push.sh cpp02 "ex01 bitti"
#
# - Sadece <modul_klasoru> içindeki değişiklikleri commit'ler.
# - Tüm repoyu GitHub'a (origin/main) pushlar.
# - O klasörün geçmişini ayırıp intra reposunun köküne pushlar.
#   Böylece intra'da ex00, ex01... doğrudan kökte olur ve commit mesajları,
#   yazar ve tarih bilgileri GitHub'dakiyle birebir aynı görünür.

set -e

GITHUB_REMOTE="origin"
GITHUB_BRANCH="main"
INTRA_BRANCH="master"

MODULE="${1%/}"
MESSAGE="$2"
INTRA_URL="$3"

if [ -z "$MODULE" ] || [ -z "$MESSAGE" ]; then
	echo "Kullanım: $0 <modul_klasoru> \"<commit mesaji>\" [intra_repo_url]"
	exit 1
fi

cd "$(dirname "$0")"

if [ ! -d "$MODULE" ]; then
	echo "Hata: '$MODULE' klasörü bulunamadı."
	exit 1
fi

# Intra URL'sini modül bazında yerel git config'e kaydet / oradan oku
if [ -n "$INTRA_URL" ]; then
	git config "intra.$MODULE.url" "$INTRA_URL"
else
	INTRA_URL="$(git config "intra.$MODULE.url" || true)"
fi
if [ -z "$INTRA_URL" ]; then
	echo "Hata: '$MODULE' için intra URL'si kayıtlı değil. İlk seferde 3. argüman olarak verin."
	exit 1
fi

# 1) Sadece bu modülü commit'le
git add -- "$MODULE"
if git diff --cached --quiet -- "$MODULE"; then
	echo "==> '$MODULE' içinde yeni değişiklik yok, sadece senkronize edilecek."
else
	git commit -m "$MESSAGE" -- "$MODULE"
fi

# 2) GitHub'a pushla (tüm repo)
echo "==> GitHub: $GITHUB_REMOTE/$GITHUB_BRANCH"
git push "$GITHUB_REMOTE" "$GITHUB_BRANCH"

# 3) Modül geçmişini ayır ve intra'ya pushla
# Modüle dokunan her commit için, sadece o klasörün içeriğini kök yapan yeni bir
# commit oluşturulur (mesaj, yazar ve tarihler korunur). Aynı girdiler hep aynı
# hash'i verdiği için intra'ya her seferinde fast-forward push yapılır.
split_module() {
	local parent="" commit tree new
	for commit in $(git rev-list --reverse HEAD -- "$1"); do
		tree=$(git rev-parse -q --verify "$commit:$1") || continue
		[ -n "$parent" ] && [ "$tree" = "$(git rev-parse "$parent^{tree}")" ] && continue
		new=$(git log -1 --format=%B "$commit" | \
			GIT_AUTHOR_NAME="$(git log -1 --format=%an "$commit")" \
			GIT_AUTHOR_EMAIL="$(git log -1 --format=%ae "$commit")" \
			GIT_AUTHOR_DATE="$(git log -1 --format=%ad --date=raw "$commit")" \
			GIT_COMMITTER_NAME="$(git log -1 --format=%cn "$commit")" \
			GIT_COMMITTER_EMAIL="$(git log -1 --format=%ce "$commit")" \
			GIT_COMMITTER_DATE="$(git log -1 --format=%cd --date=raw "$commit")" \
			git commit-tree "$tree" ${parent:+-p "$parent"})
		parent="$new"
	done
	echo "$parent"
}

echo "==> '$MODULE' geçmişi ayrılıyor..."
SPLIT=$(split_module "$MODULE")
if [ -z "$SPLIT" ]; then
	echo "Hata: '$MODULE' için commit bulunamadı."
	exit 1
fi
echo "==> Intra: $INTRA_URL ($INTRA_BRANCH)"
git push "$INTRA_URL" "$SPLIT:refs/heads/$INTRA_BRANCH"

echo "==> Tamamlandı: $MODULE hem GitHub'a hem intra'ya pushlandı."
