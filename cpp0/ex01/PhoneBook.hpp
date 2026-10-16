#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook
{
private:
	Contact	_contacts[MAX_CONTACTS];
	int		_nextIndex;
	int		_count;

	static bool			_readField(const std::string &prompt, std::string &out);
	static std::string	_formatColumn(const std::string &text);
	void				_printTable(void) const;
	void				_printContact(int index) const;
public:
	PhoneBook(void);
	~PhoneBook(void);

	bool	addContact(void);
	bool	search(void) const;

};

#endif