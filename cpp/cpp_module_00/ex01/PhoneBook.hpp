#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
    Contact _contacts[8];
    int     _count;   // nombre total ajoutés
public:
    PhoneBook();
    ~PhoneBook();

    void    add();
    void    search() const;
};

#endif
