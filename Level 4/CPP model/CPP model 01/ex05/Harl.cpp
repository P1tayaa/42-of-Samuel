#include "Harl.hpp"

#include <cstdlib>


// * og work but not with codam Standards
// void Harl::complain(std::string level)
// {
// 	std::map<std::string, Harl::Level_function>	commands = {
// 		{"debug", &Harl::debug}, {"info", &Harl::info}, {"warning", &Harl::warning}, {"error", &Harl::error}, 
// 	};
// 	if (level != "debug" && level != "info" && level != "warning" && level != "errorm") {
// 		std::cout << "wrong debug string\n";
// 		exit(1);
// 	}
// 	auto combo = commands.find(level); 
// 	Harl::Level_function function = combo->second;
// 	(this->*function)();
// }

void Harl::complain(std::string level)
{
	std::map<std::string, Harl::Level_function>	commands;
	commands["debug"] = &Harl::debug;
    commands["info"] = &Harl::info;
    commands["warning"] = &Harl::warning;
    commands["error"] = &Harl::error;
	if (commands.find(level) == commands.end()) {
		std::cout << "wrong debug string\n";
		exit(1);
	}
	Harl::Level_function function = commands.find(level)->second;
	(this->*function)();
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n";

}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}
