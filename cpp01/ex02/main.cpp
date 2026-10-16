#include <iostream>
#include <string>

int main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;	// Pointer: str'nin adresini tutar
	std::string	&stringREF = str;	// Referans: str'nin başka bir adı

	// Adresler: üçü de aynı adresi gösterir
	std::cout << "Address of str:             " << &str << std::endl;
	std::cout << "Address held by stringPTR:  " << stringPTR << std::endl;
	std::cout << "Address held by stringREF:  " << &stringREF << std::endl;

	// Değerler: üçü de aynı string'i gösterir
	std::cout << "Value of str:               " << str << std::endl;
	std::cout << "Value pointed by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed by stringREF: " << stringREF << std::endl;
	return (0);
}
