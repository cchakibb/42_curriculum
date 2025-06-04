#include "Contact.hpp"

Contact::Contact()
{
	this->first_name = "";
	this->last_name = "";
	this->nickname = "";
	this->phone_number = "";
	this->darkest_secret = "";
	// std::cout << "Constructeur de Contact appelé (par défaut)" << std::endl;
}

void Contact::initialize(const std::string& first, const std::string& last, const std::string& nick,
						const std::string& phone, const std::string& secret)
{
	this->first_name = first;
	this->last_name = last;
	this->nickname = nick;
	this->phone_number = phone;
	this->darkest_secret = secret;
}

// getters
std::string Contact::getFirstName() const
{
	return this->first_name;
}

std::string Contact::getLastName() const
{
	return this->last_name;
}

std::string Contact::getNickname() const
{
	return this->nickname;
}

std::string Contact::getPhoneNumber() const
{
	return this->phone_number;
}

std::string Contact::getDarkestSecret() const
{
	return this->darkest_secret;
}