#include "Bureaucrat.hpp"

// Please note that exception classes don’t have to be designed in
// Orthodox Canonical Form. But every other class has to.

Bureaucrat::Bureaucrat() : _name("Ezechiele")
{
	_grade = 42;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	//check if the grade is between 1 and 150 
		if (_grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (_grade > 150)
			throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	*this = src;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
	{
		//_name = rhs._name; the name is const is useless to copy it
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

// Because you don't have direct access to modify the implementation of std::ostream,
// you can't define new member functions for it. Therefore, when you want to overload
// operators involving std::ostream, such as <<, you typically do so as a non-member function.
std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs)
{
	//<name>, bureaucrat grade <grade>.
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << std::endl;

	return o;
}

// Any attempt to instantiate a Bureaucrat using an invalid grade must throw an exception:
// either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

void Bureaucrat::increment(void)
{
		if (_grade <= 1)
			throw Bureaucrat::GradeTooHighException();
		else
			_grade--;
}

void Bureaucrat::decrement(void)
{
		if (_grade >= 150)
			throw Bureaucrat::GradeTooLowException();
		else
			_grade++;
}
