#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>

#include "Contact.hpp"
#include "utils.hpp"

#define _MAX_CONTACT 8

class PhoneBook {
   private:
    Contact _contacts[_MAX_CONTACT];
    int _size;
    int _oldest;

   public:
    PhoneBook();

    void add(Contact contact);
    int getSize() const;
    void search() const;
    const Contact *getContacts() const;
};

#endif
