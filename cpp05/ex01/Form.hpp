#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

	private:
		const std::string _name;
		const int _gradeToSign;
		const int _gradeToExec;
		bool _isSigned; //false at construction

	public:
		Form();
		Form(std::string name, int gradeToSign, int gradeToExec);
		~Form();
		Form(const Form &src);
		Form &operator=(const Form &rhs);

		// getters
		const std::string getName(void) const;
		int getGradeToSign(void) const;
		int getGradeToExec(void) const;
		bool getIsSigned(void) const;

		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw();
		};

		void beSigned(Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &o, Form &form);
#endif

// • A constant name.
// • A boolean indicating whether it is signed (at construction, it’s not).
// • A constant grade required to sign it.
// • And a constant grade required to execute it.
// All these attributes are private, not protected.
