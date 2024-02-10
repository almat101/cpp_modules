#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
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
			std::string firstName;
			std::string lastName;
			std::string nickname;
			std::string phoneNumber;
			std::string darkestSecret;
			
			std::cout << "Enter first name: ";
			while(firstName.empty())
				getline(std::cin, firstName);
			contact.setFirstName(firstName);
			std::cout << "Enter last name: ";
			while(lastName.empty())
			getline(std::cin, lastName);
			contact.setLastName(lastName);
			std::cout << "Enter nickname: ";
			while (nickname.empty())
				getline(std::cin, nickname);
			contact.setNickname(nickname);
			std::cout << "Enter phone number: ";
			while (phoneNumber.empty())
				getline(std::cin, phoneNumber);
			contact.setPhoneNumber(phoneNumber);
			std::cout << "Enter darkest secret: ";
				while (darkestSecret.empty())
			getline(std::cin, darkestSecret);
			contact.setDarkestSecret(darkestSecret);
			phoneBook.addContact(contact);
		}
		else if (command == "SEARCH")
		{
			phoneBook.displayContacts();
			int index;
			std::cout << "Enter index: ";
			std::cin >> index;
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
