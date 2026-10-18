#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <cctype>

PhoneBook::PhoneBook(void) : _nextIndex(0), _count(0)
{
}

PhoneBook::~PhoneBook(void)
{
}

bool	PhoneBook::_readField(const std::string &prompt, std::string &out)
{
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, out))
			return (false);
		if (out.find_first_not_of(" \t") != std::string::npos)
			return (true);
		std::cout << "Bu alan boş bırakılamaz." << std::endl;
	}
}

bool	PhoneBook::addContact(void)
{
	std::string	firstName, lastName, nickname, phone, secret;
	if (!_readField("First name: ", firstName)
		|| !_readField("Last name: ", lastName)
		|| !_readField("Nickname: ", nickname)
		|| !_readField("Phone number: ", phone)
		|| !_readField("Darkest secret: ", secret))
		return (false);

	this->_contacts[this->_nextIndex].setContact(firstName, lastName,
												nickname, phone, secret);
	this->_nextIndex = (this->_nextIndex + 1) % MAX_CONTACTS;
	if (this->_count < MAX_CONTACTS)
		this->_count++;
	std::cout << "Kişi eklendi." << std::endl;
	return (true);
}

std::string	PhoneBook::_formatColumn(const std::string &text)
{
	if (text.length() > 10)
		return (text.substr(0, 9) + ".");
	return (text);
}

void	PhoneBook::_printTable(void) const
{
	std::cout << std::setw(10) << "index" << "|"
			  << std::setw(10) << "first name" << "|"
			  << std::setw(10) << "last name" << "|"
			  << std::setw(10) << "nickname" << std::endl;

	for (int i = 0; i < this->_count; i++)
	{
		std::cout << std::setw(10) << i << "|"
				  << std::setw(10) << _formatColumn(this->_contacts[i].getFirstName()) << "|"
				  << std::setw(10) << _formatColumn(this->_contacts[i].getLastName()) << "|"
				  << std::setw(10) << _formatColumn(this->_contacts[i].getNickname())
				  << std::endl;
	}
}

void	PhoneBook::_printContact(int index) const
{
	const Contact	c = this->_contacts[index];

	std::cout << "First name: " << c.getFirstName() << std::endl;
	std::cout << "Last name: " << c.getLastName() << std::endl;
	std::cout << "Nickname: " << c.getNickname() << std::endl;
	std::cout << "Phone number: " << c.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << c.getDarkestSecret() << std::endl;
}

bool	PhoneBook::search(void) const
{
	std::string	input;

	if (this->_count == 0)
	{
		std::cout << "Rehber boş." << std::endl;
		return (true);
	}
	_printTable();

	std::cout << "Index: ";
	if (!std::getline(std::cin, input))
		return (false);

	if (input.length() != 1 || !std::isdigit(input[0]))
	{
		std::cout << "Geçersiz indeks." << std::endl;
		return (true);
	}
	int	index = input[0] - '0';
	if (index >= this->_count)
	{
		std::cout << "Bu indekste kayıt yok." << std::endl;
		return (true);
	}
	_printContact(index);
	return (true);
}