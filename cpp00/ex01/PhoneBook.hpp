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
		Contact _contacts[8];
		int _contactCount;
};

#endif
