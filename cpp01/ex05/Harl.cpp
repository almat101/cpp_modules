#include "Harl.hpp"
#include <map>

Harl::Harl()
{
	std::cout << "Harl created!\n";
}

Harl::~Harl()
{
	std::cout << "Harl destructed!\n";
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for ears whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	t_func functionLevel[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[] = {"debug", "info", "warning", "error"};
	bool found = false;
	int numLevels = sizeof(levels) / sizeof(std::string);

	for (int i = 0; i < numLevels; i++)
	{
		if (levels[i].compare(level) == 0)
		{
			(this->*functionLevel[i])();
			found = true;
			break;
		}
	}
	if (!found)
		std::cout << "Invalid level" << std::endl;
}
