#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

// HumanB silahsız olabilir -> POINTER kullanırız.
// Pointer NULL olabilir ve sonradan değiştirilebilir.
class HumanB
{
public:
	HumanB(std::string name);
	~HumanB(void);

	void	setWeapon(Weapon &weapon);
	void	attack(void) const;

private:
	std::string	_name;
	Weapon		*_weapon;
};

#endif
