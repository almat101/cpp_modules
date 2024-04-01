#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

public:
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat & src);
	Bureaucrat & operator=(const Bureaucrat & rhs);
	//getters
	std::string getName(void) const;
	int getGrade(void) const;
};

std::ostream &	operator<<(std::ostream& o, const Bureaucrat& obj);

#endif
