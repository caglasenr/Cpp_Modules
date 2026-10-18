#include "Zombie.hpp"
#include <iostream>

int main(void)
{
	std::cout << "--- Heap zombisi (newZombie) ---" << std::endl;
	Zombie	*heapZombie = newZombie("Foo");
	heapZombie->announce();

	std::cout << "--- Stack zombisi (randomChump) ---" << std::endl;
	randomChump("Bar");

	std::cout << "--- Heap zombisini siliyoruz ---" << std::endl;
	delete heapZombie;
	return (0);
}
