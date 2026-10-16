#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
public:
	Zombie(std::string name);
	~Zombie(void);

	void	announce(void);

private:
	std::string	_name;
};

// Heap'te zombi oluşturur, dışarıda kullanılmak üzere geri döndürür
Zombie	*newZombie(std::string name);
// Stack'te zombi oluşturur, konuşturur; fonksiyon bitince zombi yok olur
void	randomChump(std::string name);

#endif
