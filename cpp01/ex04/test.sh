#!/bin/bash
# Kullanım: make && bash test.sh

echo "=== 1) Normal: cat -> dog ==="
./sedIsForLosers test.txt cat dog && cat test.txt.replace

echo "=== 2) Üst üste binen eşleşme: aa -> b (aaaa -> bb olmalı) ==="
./sedIsForLosers test.txt aa b && cat test.txt.replace

echo "=== 3) s2 boş: kelimeyi silmek ==="
./sedIsForLosers test.txt "hello " "" && cat test.txt.replace

echo "=== 4) s2, s1'i içeriyor: cat -> catcat (sonsuz döngü olmamalı) ==="
./sedIsForLosers test.txt cat catcat && cat test.txt.replace

echo "=== 5) Hata: yanlış argüman sayısı ==="
./sedIsForLosers test.txt cat

echo "=== 6) Hata: dosya yok ==="
./sedIsForLosers yok.txt cat dog

echo "=== 7) Hata: s1 boş ==="
./sedIsForLosers test.txt "" dog
