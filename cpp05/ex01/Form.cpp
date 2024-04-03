#include "Form.hpp"

Form::Form() : _name("Form"), _gradeToSign(21), _gradeToExec(42), _isSigned(false)
{
}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec), _isSigned(false)
{
	// throw exception if empty name
	if (name.empty())
		throw std::invalid_argument("Form name is empty");

	// throw exception if wrong grade
	if (gradeToSign < 1 || gradeToExec < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &src) : _name(src.getName()), _gradeToSign(src.getGradeToSign()), _gradeToExec(src.getGradeToExec()), _isSigned(src.getIsSigned())
{
}

Form::~Form()
{
}

Form &Form::operator=(const Form &rhs)
{
	if (this != &rhs)
	{
		_isSigned = rhs._isSigned;
	}
	return *this;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Form grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form grade too low";
}

const std::string Form::getName(void) const
{
	return _name;
}

int Form::getGradeToSign(void) const
{
	return _gradeToSign;
}

int Form::getGradeToExec(void) const
{
	return _gradeToExec;
}

bool Form::getIsSigned(void) const
{
	return _isSigned;
}

std::ostream &operator<<(std::ostream &o, Form &form)
{
	if (form.getIsSigned())
		o << "Form " << form.getName() << " is signed, grade to sign is " << form.getGradeToSign() << ", grade to execute is " << form.getGradeToExec() << std::endl;
	else
		o << "Form " << form.getName() << " is not signed, grade to sign is " << form.getGradeToSign() << ", grade to execute is " << form.getGradeToExec() << std::endl;

	return o;
}

/*
Add also a beSigned() member function to the Form that takes a Bureaucrat as
parameter. It changes the form status to signed if the bureaucrat’s grade is high enough
(higher or egal to the required one). Remember, grade 1 is higher than grade 2.
If the grade is too low, throw a Form::GradeTooLowException.
*/

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= this->getGradeToSign())
		this->_isSigned = true;
	else
		throw Form::GradeTooLowException();
}
