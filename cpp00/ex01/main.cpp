#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <limits>
#include <sstream>

std::string getInput(const std::string &prompt)
{
    std::string input;
    while (true)
    {
        clearerr(stdin);
        std::cin.clear();
        std::cout << prompt;
        getline(std::cin, input);
        // Check for EOF
        if (std::cin.eof())
        {
            std::cin.clear(); // Clear the EOF state
            std::cout << "EOF detected." << std::endl;
            continue;
        }
        if (!input.empty())
            break; 
    }
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
	std::cout << "Enter the index of the contact you want to display: ";
	clearerr(stdin);
	std::cin.clear();
	std::cout << str_index;
	getline(std::cin, str_index);
	if (std::cin.eof())
	{
        std::cin.clear(); // Clear the EOF state
        std::cout << "EOF detected." << std::endl;
        return;
    }
	if (str_index.empty())
	{
		std::cout << "invalid index." << std::endl;
		return;
	}
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
		clearerr(stdin);
		std::cin.clear();
		getline(std::cin, command);
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
