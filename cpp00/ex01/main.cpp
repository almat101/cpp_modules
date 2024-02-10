#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <limits>

std::string getInput(const std::string &prompt)
{
	std::string input;
	std::cout << prompt;
	while (input.empty())
		getline(std::cin, input);
	return input;
}

int main(void)
{
	PhoneBook phoneBook;
	std::string command;
	while (true)
	{
		std::cout << "Enter a command: ";
		std::cin >> command;
		if (command == "ADD")
		{
			Contact contact;
			contact.setFirstName(getInput("Enter first name: "));
			contact.setLastName(getInput("Enter last name: "));
			contact.setNickname(getInput("Enter nickname: "));
			contact.setPhoneNumber(getInput("Enter phone number: "));
			contact.setDarkestSecret(getInput("Enter darkest secret: "));
			phoneBook.addContact(contact);
		}
		else if (command == "SEARCH")
		{
			phoneBook.displayContacts();
			int index;
			std::cout << "Enter index: ";
			std::cin >> index;
			while (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input! Please try again with valid index: ";
				std::cin >> index;
			}
			phoneBook.displayContact(index);
		}
		else if (command == "EXIT")
		{
			break;
		}
		else
		{
			std::cout << "Invalid command." << std::endl;
		}
	}
	return 0;
}
