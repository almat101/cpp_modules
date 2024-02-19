#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
	public:
		Contact();
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
		std::string getPhoneNumber()const;
		std::string getDarkestSecret() const;
		void setFirstName(std::string);
		void setLastName(std::string);
		void setNickname(std::string);
		void setPhoneNumber(std::string);
		void setDarkestSecret(std::string);
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
};

#endif
