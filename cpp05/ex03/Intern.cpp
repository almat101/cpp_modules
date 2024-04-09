#include "Intern.hpp"

// AForm* createPresidentialPardonForm(std::string target)
// {
// 	AForm* tmp;
// 	try
// 	{
// 		tmp = new PresidentialPardonForm(target);
// 	}
// 	catch (std::bad_alloc& ba)
// 	{
// 		std::cerr << "bad_alloc caught: " << ba.what() << '\n';
// 		return NULL;
// 	}
// 	return tmp;
// }

// AForm* createRobotomyRequestForm(std::string target)
// {
// 	AForm* tmp;
// 	try
// 	{
// 		tmp = new RobotomyRequestForm(target);
// 	}
// 	catch (std::bad_alloc& ba)
// 	{
// 		std::cerr << "bad_alloc caught: " << ba.what() << '\n';
// 		return NULL;
// 	}
// 	return tmp;
// }

// AForm* createShrubberyCreationForm(std::string target)
// {
// 	AForm* tmp;
// 	try
// 	{
// 		tmp = new ShrubberyCreationForm(target);
// 	}
// 	catch (std::bad_alloc& ba)
// 	{
// 		std::cerr << "bad_alloc caught: " << ba.what() << '\n';
// 		return NULL;
// 	}
// 	return tmp;
// }


Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(const Intern &src)
{
	*this = src;
}

Intern& Intern::operator=(const Intern & rhs)
{
	(void)rhs;
	return *this;
}

/*
However, the intern has one important capacity: the makeForm() function. It takes
two strings. The first one is the name of a form and the second one is the target of the
form. It return a pointer to a Form object (whose name is the one passed as parameter)
whose target will be initialized to the second parameter.
It will print something like:
Intern creates <form>
If the form name passed as parameter doesn’t exist, print an explicit error message.
*/


AForm* Intern::makeForm(std::string form_name, std::string target)
{
	if (form_name.empty() || target.empty())
	{
		std::cout << "Intern cannot work with empty string" << std::endl;
		return (NULL);
	}
	AForm *forms[3];
	try
	{
		forms[0] = new PresidentialPardonForm(target);
		forms[1] = new RobotomyRequestForm(target);
		forms[2] = new ShrubberyCreationForm(target);
	}
	catch (std::bad_alloc& ba) {
		std::cerr << "bad_alloc caught: " << ba.what() << '\n';
		return NULL;
	}

	std::string form_name_lower = form_name;
	for (size_t i = 0; i < form_name_lower.length(); i++)
		form_name_lower[i] = tolower(form_name_lower[i]);

	std::string targets[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	for (int i = 0; i < 3; i++)
	{
		if (targets[i] == form_name_lower)
		{
			std::cout << "Intern creates " << form_name << std::endl;
		for (int j = 0; j < 3; j++)
		{
			if (i != j)
				delete forms[j];
		}
		return (forms[i]);
			return (forms[i]);
		}
	}
	for (int i = 0; i < 3; i++)
		delete forms[i];
	std::cout << "Intern cannot create " << form_name << std::endl;
	return (NULL);
}


// AForm* Intern::makeForm(std::string form_name, std::string target)
// {
// 	typedef std::map<std::string, FormCreator> FormCreatorMap;
// 	FormCreatorMap formCreators;
// 	formCreators["presidential pardon"] = createPresidentialPardonForm;
// 	formCreators["robotomy request"] = createRobotomyRequestForm;
// 	formCreators["shrubbery creation"] = createShrubberyCreationForm;

// 	if (form_name.empty() || target.empty())
// 	{
// 		std::cout << "Intern cannot work with empty string" << std::endl;
// 		return (NULL);
// 	}
// 	if (formCreators.find(form_name) != formCreators.end()) {
// 		AForm* form = formCreators[form_name](target);
// 		std::cout << "Intern creates " << form_name << std::endl;
// 		return form;
// 	} else {
// 		std::cout << "Intern cannot create " << form_name << std::endl;
// 		return NULL;
// 	}
// }
