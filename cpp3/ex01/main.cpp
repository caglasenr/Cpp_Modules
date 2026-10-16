#include "ScavTrap.hpp"

int main()
{
	std::cout << "--- ClapTrap ---" << std::endl;
	{
		ClapTrap clap("Clappy");
		clap.attack("a target dummy");
		clap.takeDamage(4);
		clap.beRepaired(2);
	}

	std::cout << std::endl << "--- ScavTrap construction chain ---" << std::endl;
	{
		ScavTrap scav("Serena");

		std::cout << std::endl << "--- ScavTrap actions ---" << std::endl;
		scav.attack("a bandit");
		scav.takeDamage(30);
		scav.beRepaired(10);
		scav.guardGate();

		std::cout << std::endl << "--- ScavTrap copy ---" << std::endl;
		ScavTrap copy(scav);
		ScavTrap assigned;
		assigned = scav;
		copy.attack("a skag");

		std::cout << std::endl << "--- Destruction chain (reverse order) ---" << std::endl;
	}

	std::cout << std::endl << "--- Through a ClapTrap pointer ---" << std::endl;
	{
		ClapTrap *ptr = new ScavTrap("Pointy");
		ptr->attack("a psycho");
		delete ptr;
	}
	return 0;
}
