#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <sstream>
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
		PhoneBook(void);

		const Contact *getContacts(void) const;
		int           getSize(void) const;

		void add(Contact contact);
		void search(void) const;
		int displayInfo(std::string const &indexStr) const;
};

#endif
