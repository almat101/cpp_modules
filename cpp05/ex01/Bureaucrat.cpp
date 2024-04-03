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
	if (name.empty())
		throw std::invalid_argument("Bureaucrat name is empty");
	// check if the grade is between 1 and 150
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
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

/*
Lastly, add a signForm() member function to the Bureaucrat. If the form got signed,
it will print something like:
<bureaucrat> signed <form>
Otherwise, it will print something like:
<bureaucrat> couldn’t sign <form> because <reason>.
Implement and turn in some tests to ensure everything works as expected.
*/

void Bureaucrat::signForm(Form &form)
{
	// wrong way we have to check if the form got signed calling the beSigned()
	// if (form.getIsSigned())
	// 	std::cout << _name << " signed " << form.getName() << std::endl;
	// else
	// 	std::cout << _name << " couldn't sign " << form.getName() << " because has lower grade!" << std::endl;

	// and we have to use exception , in this way we try to call the form.beSigned()
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cout  << _name << " couldn't sign " << form.getName() << " because " << e.what() << '\n';
	}
}
