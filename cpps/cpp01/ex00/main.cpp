#include "Zombie.hpp"
#include <iostream>

int main(void)
{
	std::cout << "--- Heap zombisi (newZombie) ---" << std::endl;
	Zombie	*heapZombie = newZombie("Foo");
	heapZombie->announce();

	std::cout << "--- Stack zombisi (randomChump) ---" << std::endl;
	randomChump("Bar");	// Fonksiyon bitince Bar kendiliğinden yok olur

	std::cout << "--- Heap zombisini siliyoruz ---" << std::endl;
	delete heapZombie;	// Heap'teki zombiyi biz silmek zorundayız
	return (0);
}
