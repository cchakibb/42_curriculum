#include "PhoneBook.hpp"
#include <iostream>

int main()
{
	PhoneBook myPhoneBook;
	
	std::string command;

	std::cout << "--- Welcome to your Awesome PhoneBook! ---" << std::endl;
	std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;

	while (true)
	{
		std::cout << "> ";
		std::getline(std::cin, command);

		if (std::cin.eof())
		{
			std::cout << std::endl << "You exited the PhoneBook. Goodbye!" << std::endl;
			break ;
		}
		if (command == "ADD")
			myPhoneBook.addContact();
		else if (command == "SEARCH")
			myPhoneBook.searchContacts();
		else if (command == "EXIT")
		{
			std::cout << std::endl << "You exited the PhoneBook. Goodbye!" << std::endl;
			break ;
		}
	}
	return 0;
}