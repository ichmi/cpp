#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include "utils.hpp"

class Contact {
   private:
    std::string _first;
    std::string _last;
    std::string _nick;
    std::string _phone;
    std::string _secret;

   public:
    Contact();
    Contact(std::string name, std::string last, std::string nick,
            std::string phone, std::string secret);
    std::string getFirst() const;
    std::string getLast() const;
    std::string getNick() const;
    std::string getPhone() const;
    std::string getSecret() const;
    static Contact create(void);

    operator bool() const;
};

#endif
