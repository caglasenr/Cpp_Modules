#include "Zombie.hpp"

// STACK: zombi sadece bu fonksiyonun içinde lazım.
// Fonksiyon bitince otomatik yok edilir, delete gerekmez.
void	randomChump(std::string name)
{
	Zombie	zombie(name);

	zombie.announce();
}
