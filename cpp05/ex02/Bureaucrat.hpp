#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;
class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;

	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat &operator=(const Bureaucrat &rhs);

		// getters
		std::string getName(void) const;
		int getGrade(void) const;

		// nested class that inherit from std::exception
		class GradeTooLowException : public std::exception
		{
			// this function has to be virtual because override the method what() of the base class std::exception that is already virtual
			// this is the declaration of what() in std::exception in c++98
			virtual const char *what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw();
		};

		void increment(void);
		void decrement(void);

		void signForm(AForm &f);

		void executeForm(AForm const & form);
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs);

#endif
