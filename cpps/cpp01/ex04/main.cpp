#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// text içindeki bütün s1'leri s2 ile değiştirip yeni bir string döner.
// std::string::replace yasak, bu yüzden parça parça yeni string kuruyoruz.
static std::string	replaceAll(const std::string &text,
								const std::string &s1, const std::string &s2)
{
	std::string	result;
	size_t		start = 0;
	size_t		found = text.find(s1, start);

	while (found != std::string::npos)
	{
		result += text.substr(start, found - start);	// s1'den önceki kısım
		result += s2;									// s1 yerine s2
		start = found + s1.length();					// s1'in sonrasından devam
		found = text.find(s1, start);
	}
	result += text.substr(start);	// Son eşleşmeden sonra kalan kısım
	return (result);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];

	// s1 boşsa find her yerde eşleşir ve sonsuz döngü olur
	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be empty" << std::endl;
		return (1);
	}

	// Dosyayı aç (C++98'de ifstream const char* ister -> c_str())
	std::ifstream	infile(filename.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error: cannot open " << filename << std::endl;
		return (1);
	}

	// Dosyanın tamamını tek string'e oku
	std::stringstream	buffer;
	buffer << infile.rdbuf();
	infile.close();

	// Çıktı dosyasını oluştur
	std::string		outName = filename + ".replace";
	std::ofstream	outfile(outName.c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error: cannot create " << outName << std::endl;
		return (1);
	}

	outfile << replaceAll(buffer.str(), s1, s2);
	outfile.close();
	return (0);
}
