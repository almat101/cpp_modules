#include "Contact.hpp"

Contact::Contact()
{
}

std::string Contact::getFirstName()
{
	return _firstName;
}

std::string Contact::getLastName()
{
	return _lastName;
}

std::string Contact::getNickname()
{
	return _nickname;
}

std::string Contact::getPhoneNumber()
{
	return _phoneNumber;
}

std::string Contact::getDarkestSecret()
{
	return _darkestSecret;
}

void Contact::setFirstName(std::string firstName)
{
	_firstName = firstName;
}

void Contact::setLastName(std::string lastName)
{
	_lastName = lastName;
}

void Contact::setNickname(std::string nickname)
{
	_nickname = nickname;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
	_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret)
{
	_darkestSecret = darkestSecret;
}

