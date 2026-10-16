#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : _name(name)
{
}

// Destructor, zombi yok edilirken adını basar (hata ayıklama için)
Zombie::~Zombie(void)
{
	std::cout << this->_name << " is destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
