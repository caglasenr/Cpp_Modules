#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " is dead and can't attack!" << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " has no energy left to attack!" << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "ScavTrap " << this->_name << " fiercely attacks " << target
		<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}
