#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>
# include <vector>
# include <map>

class Harl
{
    public:
    Harl() {};
    ~Harl() {};
	void complain(std::string level);
	using Level_function = void (Harl::*)(void);
	
	private:
    void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};

# endif