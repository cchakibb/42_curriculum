#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
// #include <string>

class PhoneBook {
public:
	PhoneBook(); 

	void addContact();
	void searchContacts();

private:
	Contact contacts[8];
	int contactCount;
	int oldestContactIndex;
};

#endif