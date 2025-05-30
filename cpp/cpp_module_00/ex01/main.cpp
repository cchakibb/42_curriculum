#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main()
{
    PhoneBook pb;
    std::string cmd;

    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, cmd))
            break;  // EOF
        if (cmd == "ADD")
            pb.add();
        else if (cmd == "SEARCH")
            pb.search();
        else if (cmd == "EXIT")
            break;
        // toute autre saisie est ignorée
    }
    return 0;
}
