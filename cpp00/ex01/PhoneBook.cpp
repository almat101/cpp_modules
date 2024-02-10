#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook()
{
	_contactCount = 0;
}

void PhoneBook::addContact(Contact contact)
{
	if (_contactCount < 8)
	{
		_contacts[_contactCount] = contact;
		_contactCount++;
	}
	else
	{
		//replace the cout with the oldest contact
		std::cout << "Phone book is full." << std::endl;
	}
}

void PhoneBook::displayContacts()
{
	std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
	for (int i = 0; i < _contactCount; i++)
	{
		std::string firstName = _contacts[i].getFirstName();
		std::string lastName = _contacts[i].getLastName();
		std::string nickname = _contacts[i].getNickname();

		if (firstName.size() > 9)
			firstName = firstName.substr(0, 9) + ".";
		if (lastName.size() > 9)
			lastName = lastName.substr(0, 9) + ".";
		if (nickname.size() > 9)
			nickname = nickname.substr(0, 9) + ".";

		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << firstName << "|";
		std::cout << std::setw(10) << lastName << "|";
		std::cout << std::setw(10) << nickname << std::endl;
	}
}

void PhoneBook::displayContact(int index)
{
	if (index >= 0 && index < _contactCount)
	{
		std::cout << "First Name: " << _contacts[index].getFirstName() << std::endl;
		std::cout << "Last Name: " << _contacts[index].getLastName() << std::endl;
		std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
		std::cout << "Phone Number: " << _contacts[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << _contacts[index].getDarkestSecret() << std::endl;
	}
	else
	{
		std::cout << "Invalid index." << std::endl;
	}
}


