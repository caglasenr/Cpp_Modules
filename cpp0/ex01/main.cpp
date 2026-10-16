#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phoneBook;
	std::string	command;

	while (true)
	{
		std::cout << "Komut girin (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
			break ;

		if (command == "ADD")
		{
			if (!phoneBook.addContact())
				break ;
		}
		else if (command == "SEARCH")
		{
			if (!phoneBook.search())
				break ;
		}
		else if (command == "EXIT")
			break ;
	}
	std::cout << std::endl;
	return (0);
}