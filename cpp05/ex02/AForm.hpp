#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{

	private:
		const std::string _name;
		const int _gradeToSign;
		const int _gradeToExec;
		bool _isSigned; //false at construction

	public:
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExec);
		virtual ~AForm(); //virtual destructor to make class abstract
		AForm(const AForm &src);
		AForm &operator=(const AForm &rhs);

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

		class FormNotSignedException : public std::exception
		{
			virtual const char *what() const throw();
		};

		void beSigned(Bureaucrat &b);

		//pure virtual function that makes form abstract (with virtual destructor)
		virtual void execute(Bureaucrat const & executor) const = 0;

		//validation function that checks if the form can be executed
		void validation(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &o, AForm &AForm);
#endif

/*
In all cases, the base class AForm must be an abstract class, and therefore should be
renamed AForm. Keep in mind the AForm’s attributes need to remain private and that
they are in the base class.
*/
