#include "Zombie.hpp"
#include <iostream>

int main(void)
{
	int		N = 5;
	Zombie	*horde = zombieHorde(N, "Walker");

	if (horde == NULL)
		return (1);

	for (int i = 0; i < N; i++)
		horde[i].announce();

	// new[] ile ayrılan bellek delete[] ile silinir (delete değil!)
	delete[] horde;
	return (0);
}
