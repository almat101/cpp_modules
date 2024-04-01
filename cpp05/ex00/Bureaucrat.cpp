#include "Bureaucrat.hpp"

//Please note that exception classes don’t have to be designed in
//Orthodox Canonical Form. But every other class has to.

Bureaucrat::Bureaucrat(){}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) , _grade(grade){}

Bureaucrat::Bureaucrat(const Bureaucrat & src)
{
	*this = src;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & rhs)
{
	if (this != &rhs)
	{
		//_name = rhs._name; the name is const
		_grade = rhs._grade;
	}
	return *this;

}

std::string Bureaucrat::getName(void) const
{
	return _name;
}

int Bureaucrat::getGrade(void) const
{
	return _grade;
}
