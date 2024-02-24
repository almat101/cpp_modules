#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
public:
	Harl();
	~Harl();
	void complain(std::string level);

private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};

typedef void(Harl::*t_func) (void); //new type t_func which is a pointer to a member function of Harl class

#endif
