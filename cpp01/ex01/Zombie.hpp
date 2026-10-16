#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
public:
	Zombie(void);	// new Zombie[N] için parametresiz constructor şart
	~Zombie(void);

	void	announce(void);
	void	setName(std::string name);

private:
	std::string	_name;
};

// Tek bir new[] ile N zombi oluşturur, ilk zombinin adresini döner
Zombie	*zombieHorde(int N, std::string name);

#endif
