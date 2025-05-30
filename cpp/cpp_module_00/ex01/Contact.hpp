#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;

public:
    Contact();
    ~Contact();

    // setters
    void setFirstName(const std::string& s);
    void setLastName(const std::string& s);
    void setNickname(const std::string& s);
    void setPhoneNumber(const std::string& s);
    void setDarkestSecret(const std::string& s);

    // getters
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
};

#endif
