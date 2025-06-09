#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

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