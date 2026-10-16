#include "ClapTrap.hpp"

int main()
{
	std::cout << "--- Constructors ---" << std::endl;
	ClapTrap a("Clappy");
	ClapTrap b(a);
	ClapTrap c;
	c = a;

	std::cout << std::endl << "--- Attack / damage / repair ---" << std::endl;
	a.attack("a target dummy");
	a.takeDamage(3);
	a.beRepaired(2);

	std::cout << std::endl << "--- Running out of energy ---" << std::endl;
	for (int i = 0; i < 10; i++)
		b.attack("the wall");
	b.attack("the wall");
	b.beRepaired(5);

	std::cout << std::endl << "--- Death ---" << std::endl;
	c.takeDamage(100);
	c.attack("anyone");
	c.beRepaired(10);
	c.takeDamage(1);

	std::cout << std::endl << "--- Destructors ---" << std::endl;
	return 0;
}
