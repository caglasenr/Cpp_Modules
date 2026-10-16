#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << "--- ClapTrap ---" << std::endl;
	{
		ClapTrap clap("Clappy");
		clap.attack("a target dummy");
		clap.takeDamage(4);
		clap.beRepaired(2);
	}

	std::cout << std::endl << "--- ScavTrap ---" << std::endl;
	{
		ScavTrap scav("Serena");
		scav.attack("a bandit");
		scav.guardGate();
	}

	std::cout << std::endl << "--- FragTrap construction chain ---" << std::endl;
	{
		FragTrap frag("Fraggy");

		std::cout << std::endl << "--- FragTrap actions ---" << std::endl;
		frag.attack("a skag");
		frag.takeDamage(45);
		frag.beRepaired(15);
		frag.highFivesGuys();

		std::cout << std::endl << "--- FragTrap copy ---" << std::endl;
		FragTrap copy(frag);
		FragTrap assigned;
		assigned = frag;
		assigned.highFivesGuys();

		std::cout << std::endl << "--- FragTrap death ---" << std::endl;
		copy.takeDamage(200);
		copy.attack("nobody");
		copy.highFivesGuys();

		std::cout << std::endl << "--- Destruction chain (reverse order) ---" << std::endl;
	}
	return 0;
}
