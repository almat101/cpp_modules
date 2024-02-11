#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();
	void addContact(Contact contact);
	void displayContacts();
	void displayContact(int index);

private:
	const static int _maxContacts = 8;
	Contact _contacts[_maxContacts];
	int _contactCount;
	int _oldest;
};

#endif
