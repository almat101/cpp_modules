#include "AForm.hpp"

AForm::AForm() : _name("AForm"), _gradeToSign(21), _gradeToExec(42), _isSigned(false)
{
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec) : _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec), _isSigned(false)
{
	// throw exception if empty name
	if (name.empty())
		throw std::invalid_argument("AForm name is empty");

	// throw exception if wrong grade
	if (gradeToSign < 1 || gradeToExec < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &src) : _name(src.getName()), _gradeToSign(src.getGradeToSign()), _gradeToExec(src.getGradeToExec()), _isSigned(src.getIsSigned())
{
}

AForm::~AForm()
{
}

AForm &AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
	{
		_isSigned = rhs._isSigned;
	}
	return *this;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Form grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Form grade too low";
}

const char *AForm::FormAlreadySigned::what() const throw()
{
	return "Form already signed";
}

const std::string AForm::getName(void) const
{
	return _name;
}

int AForm::getGradeToSign(void) const
{
	return _gradeToSign;
}

int AForm::getGradeToExec(void) const
{
	return _gradeToExec;
}

bool AForm::getIsSigned(void) const
{
	return _isSigned;
}

std::ostream &operator<<(std::ostream &o, AForm &AForm)
{
	if (AForm.getIsSigned())
		o << "AForm " << AForm.getName() << " is signed, grade to sign is " << AForm.getGradeToSign() << ", grade to execute is " << AForm.getGradeToExec() << std::endl;
	else
		o << "AForm " << AForm.getName() << " is not signed, grade to sign is " << AForm.getGradeToSign() << ", grade to execute is " << AForm.getGradeToExec() << std::endl;

	return o;
}

/*
Add also a beSigned() member function to the AForm that takes a Bureaucrat as
parameter. It changes the AForm status to signed if the bureaucrat’s grade is high enough
(higher or egal to the required one). Remember, grade 1 is higher than grade 2.
If the grade is too low, throw a AForm::GradeTooLowException.
*/

void AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= this->getGradeToSign())
		this->_isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

/*
Whether you want to check the requirements in every concrete class or in the base
class (then call another function to execute the form) is up to you. However, one way is
prettier than the other one.
*/
void AForm::validation(Bureaucrat const & executor) const
{
	if (this->getIsSigned())
		throw AForm::FormAlreadySigned();
	else if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();
}
