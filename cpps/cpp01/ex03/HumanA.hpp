#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

// HumanA her zaman silahlıdır -> REFERANS kullanırız.
// Referans boş olamaz ve constructor'da bağlanmak zorundadır.
class HumanA
{
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA(void);

	void	attack(void) const;

private:
	std::string	_name;
	Weapon		&_weapon;
};

#endif
