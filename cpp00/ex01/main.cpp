#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <limits>
#include <sstream>

std::string getInput(const std::string &prompt)
{
	std::string input;
	std::cout << prompt;
	while (input.empty())
		getline(std::cin, input);
	return input;
}

int str_to_positive_int(std::string s)
{
	for (int i = 0; i < (int)s.length(); i++)
	{
		if (!isdigit(s[i]))
			return -1;
	}
	int i = 0;
	std::istringstream(s) >> i;
	return i;
}


void add(PhoneBook &phoneBook)
{
	Contact contact;
	contact.setFirstName(getInput("Enter first name: "));
	contact.setLastName(getInput("Enter last name: "));
	contact.setNickname(getInput("Enter nickname: "));
	contact.setPhoneNumber(getInput("Enter phone number: "));
	contact.setDarkestSecret(getInput("Enter darkest secret: "));
	phoneBook.addContact(contact);
}

void search(PhoneBook &phoneBook)
{
	phoneBook.displayContacts();
	std::string str_index;
	std::cout << "Enter index: ";
	std::cin >> str_index;
	int index = str_to_positive_int(str_index);
	phoneBook.displayContact(index);
}

int main(void)
{
	PhoneBook phoneBook;
	std::string command;
	while (true)
	{
		std::cout << "Enter a command: ADD, SEARCH, or EXIT" << std::endl;
		std::cin >> command;
		if (command == "ADD")
			add(phoneBook);
		else if (command == "SEARCH")
			search(phoneBook);
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Invalid command." << std::endl;
	}
	return 0;
}
