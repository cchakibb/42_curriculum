#include "PhoneBook.hpp"
#include <iostream>
#include <limits>
#include <cstdio>
#include <iomanip> // for std::setw
#include <cstdlib> // for atoi

PhoneBook::PhoneBook()
{
	this->contactCount = 0;
	this->oldestContactIndex = 0;
};

void	PhoneBook::addContact()
{
	std::string firstNameInput;
	std::string lastNameInput;
    std::string nicknameInput;
    std::string phoneNumberInput;
    std::string darkestSecretInput;

	while (true)
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, firstNameInput);
		if (std::cin.eof())
		{
			std::cout << std::endl << "Input aborted. Returning to main menu." << std::endl;
			std::cin.clear();
			clearerr(stdin);
			return ;
		}
		if (!firstNameInput.empty())
			break ;
		std::cout << "Field can't be empty. Please try again." << std::endl;
	}
	while (true)
	{
		std::cout << "Enter last name: ";
		std::getline(std::cin, lastNameInput);
		if (std::cin.eof())
		{
			std::cout << std::endl << "Input aborted. Returning to main menu." << std::endl;
			std::cin.clear();
			clearerr(stdin);
			return ;
		}
		if (!lastNameInput.empty())
			break ;
		std::cout << "Field can't be empty. Please try again." << std::endl;
	}
	while (true)
	{
        std::cout << "Enter nickname: ";
        std::getline(std::cin, nicknameInput);
        if (std::cin.eof())
		{
            std::cout << std::endl << "Input aborted. Returning to main menu." << std::endl;
            std::cin.clear();
            clearerr(stdin);
            return;
        }
        if (!nicknameInput.empty())
            break;
        std::cout << "Field cannot be empty. Please try again." << std::endl;
    }

	while (true)
	{
        std::cout << "Enter phone number: ";
        std::getline(std::cin, phoneNumberInput);
        if (std::cin.eof())
		{
            std::cout << std::endl << "Input aborted. Returning to main menu." << std::endl;
            std::cin.clear();
            clearerr(stdin);
            return;
        }
        if (!phoneNumberInput.empty())
            break;
        std::cout << "Field cannot be empty. Please try again." << std::endl;
    }
	while (true)
	{
        std::cout << "Enter darkest secret: ";
        std::getline(std::cin, darkestSecretInput);
        if (std::cin.eof())
		{
            std::cout << std::endl << "Input aborted. Returning to main menu." << std::endl;
            std::cin.clear();
            clearerr(stdin);
            return;
        }
        if (!darkestSecretInput.empty())
            break;
        std::cout << "Field cannot be empty. Please try again." << std::endl;
    }

	this->contacts[this->oldestContactIndex].initialize(firstNameInput, lastNameInput, nicknameInput, phoneNumberInput, darkestSecretInput);

	this->oldestContactIndex = (this->oldestContactIndex + 1) % 8;

	if (this->contactCount < 8)
		this->contactCount++;
	std::cout << "Contact added successfully!" << std::endl;
};

static void printFormattedColumn(const std::string &text)
{
	if (text.length() > 10)
		std::cout << text.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << text;
}

void	PhoneBook::searchContacts()
{
	if (this->contactCount == 0)
	{
		std::cout << "Phonebook is empty. Please ADD a contact first." << std::endl;
		return ;
	}
	std::cout << std::right;
	std::cout << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nickname" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;

	for (int i = 0; i < this->contactCount; i++)
	{
		std::cout << std::setw(10) << i << "|";
		printFormattedColumn(this->contacts[i].getFirstName());
		std::cout << "|";
		printFormattedColumn(this->contacts[i].getLastName());
		std::cout << "|";
		printFormattedColumn(this->contacts[i].getNickname());
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------" << std::endl;

	int index = -1;
	while (true)
	{
		std::cout << "Enter the index of the contact to display: ";
		std::string input;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl << "Input aborted. Returning to main menu." << std::endl;
			std::cin.clear();
			clearerr(stdin);
			return ;
		}
		bool isNumeric = true;
		if (input.empty())
			isNumeric = false;
		else
		{
			for (size_t i = 0; i < input.length(); ++i)
			{
				if (!std::isdigit(input[i]))
				{
					isNumeric = false;
					break ;
				}
			}
		}
		if (isNumeric)
		{
			index = std::atoi(input.c_str());
			if (index >= 0 && index < this->contactCount)
				break ; // valid index
		}
		std::cout << "Invalid index. Please try again." << std::endl;
	}
	std::cout << std::endl << "--- Contact Details ---" << std::endl;
	std::cout << "First Name:     " << this->contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name:      " << this->contacts[index].getLastName() << std::endl;
    std::cout << "Nickname:       " << this->contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number:   " << this->contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << this->contacts[index].getDarkestSecret() << std::endl;
    std::cout << "-----------------------" << std::endl;
};