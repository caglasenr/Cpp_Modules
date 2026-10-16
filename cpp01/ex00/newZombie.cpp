#include "Zombie.hpp"

// HEAP: new ile oluşturulan zombi fonksiyon bitince yaşamaya devam eder.
// Bu yüzden onu kullanan kişi işi bitince delete etmek zorundadır.
Zombie	*newZombie(std::string name)
{
	return (new Zombie(name));
}
