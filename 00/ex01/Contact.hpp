#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cstdlib>
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

		std::string getFirst(void) const;
		std::string getLast(void) const;
		std::string getNick(void) const;
		std::string getPhone(void) const;
		std::string getSecret(void) const;
		static Contact create(void);

		operator bool(void) const;
};

#endif
