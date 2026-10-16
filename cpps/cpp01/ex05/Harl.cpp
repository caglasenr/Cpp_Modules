#include "Harl.hpp"
#include <iostream>

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl
			  << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
			  << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl
			  << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
			  << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl
			  << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month."
			  << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl
			  << "This is unacceptable! I want to speak to the manager now."
			  << std::endl;
}

// if/else ormanı yerine: seviye isimleri ve üye fonksiyon pointer'ları
// aynı sırada iki dizide. İsmi bul, aynı indeksteki fonksiyonu çağır.
void	Harl::complain(std::string level)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void		(Harl::*functions[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*functions[i])();	// Üye fonksiyon pointer'ı ile çağrı
			return ;
		}
	}
	std::cout << "[ Unknown level: " << level << " ]" << std::endl;
}
