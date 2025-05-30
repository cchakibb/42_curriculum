#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>   // pour std::setw et std::right
#include <limits>    // pour std::numeric_limits

PhoneBook::PhoneBook(): _count(0) {}
PhoneBook::~PhoneBook() {}

static std::string prompt(const std::string& field)
{
    std::string input;
    do {
        std::cout << field << ": ";
        if (!std::getline(std::cin, input))
            return std::string(); // EOF
    } while (input.empty());
    return input;
}

void PhoneBook::add()
{
    int idx = _count % 8;  // écrase l'ancien contact au-delà du 8ᵉ
    _contacts[idx].setFirstName(   prompt("First Name")   );
    _contacts[idx].setLastName(    prompt("Last Name")    );
    _contacts[idx].setNickname(    prompt("Nickname")     );
    _contacts[idx].setPhoneNumber( prompt("Phone Number") );
    _contacts[idx].setDarkestSecret(prompt("Darkest Secret"));

    ++_count;
}

static void printColumn(const std::string& s)
{
    if (s.length() > 10)
        std::cout << s.substr(0, 9) << '.';
    else
        std::cout << std::setw(10) << std::right << s;
}

void PhoneBook::search() const
{
    if (_count == 0)
    {
        std::cout << "PhoneBook is empty.\n";
        return;
    }
    // entête
    std::cout << std::setw(10) << std::right << "Index" << '|'
              << std::setw(10) << std::right << "First Name" << '|'
              << std::setw(10) << std::right << "Last Name"  << '|'
              << std::setw(10) << std::right << "Nickname"   << '\n';

    int displayed = std::min(_count, 8);
    for (int i = 0; i < displayed; ++i)
    {
        std::cout << std::setw(10) << std::right << i << '|';
        printColumn(_contacts[i].getFirstName());   std::cout << '|';
        printColumn(_contacts[i].getLastName());    std::cout << '|';
        printColumn(_contacts[i].getNickname());    std::cout << '\n';
    }

    std::cout << "Enter index: ";
    int idx;
    if (!(std::cin >> idx) || idx < 0 || idx >= displayed)
    {
        std::cout << "Invalid index.\n";
    }
    else
    {
        // consommer le newline restant
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        const Contact& c = _contacts[idx];
        std::cout
            << "First Name: "   << c.getFirstName()   << '\n'
            << "Last Name: "    << c.getLastName()    << '\n'
            << "Nickname: "     << c.getNickname()    << '\n'
            << "Phone Number: " << c.getPhoneNumber() << '\n'
            << "Darkest Secret:"<< c.getDarkestSecret()<< '\n';
    }
}
