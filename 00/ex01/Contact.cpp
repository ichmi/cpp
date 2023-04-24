#include "Contact.hpp"

Contact::Contact(void) {}

Contact::Contact(std::string name, std::string last, std::string nick,
                 std::string phone, std::string secret)
    : _first(name), _last(last), _nick(nick), _phone(phone), _secret(secret) {}

Contact::operator bool(void) const {
    return (
		this->_first != "" && 
		this->_last != "" && 
		this->_nick != "" && 
		this->_phone != "" &&
		this->_secret != ""
	);
}

std::string Contact::getFirst(void) const { return this->_first; }
std::string Contact::getLast(void) const { return this->_last; }
std::string Contact::getNick(void) const { return this->_nick; }
std::string Contact::getPhone(void) const { return this->_phone; }
std::string Contact::getSecret(void) const { return this->_secret; }

Contact Contact::create(void) {
	std::string first, last, nick, phone, secret;

	while (first.empty()) {
		std::cout << GRAY "First name: " GREEN;
		std::getline(std::cin, first);
		std::cout << RES;
		if (std::cin.eof()) {
			std::cout << RED "EOF received" RES << std::endl;
			std::exit(1);
		}
		first = initName(first);
		if (!first.empty()) {
			break ;
		}
		std::cout << _ERR "Invalid first name" RES << std::endl;
	}

	while (last.empty()) {
		std::cout << GRAY "Last name: " GREEN;
		std::getline(std::cin, last);
		std::cout << RES;
		if (std::cin.eof()) {
			std::cout << RED "EOF received" RES << std::endl;
			std::exit(1);
		}
		last = initName(last);
		if (!last.empty()) {
			break ;
		}
		std::cout << _ERR "Invalid last name" RES << std::endl;
	}

	while (nick.empty()) {
		std::cout << GRAY "Nickname: " GREEN;
		std::getline(std::cin, nick);
		std::cout << RES;
		if (std::cin.eof()) {
			std::cout << RED "EOF received" RES <<  std::endl;
			std::exit(1);
		}
		nick = initMessage(nick);
		if (!nick.empty()) {
			break ;
		}
		std::cout << _ERR "Invalid nickname" RES << std::endl;
	}

	while (phone.empty()) {
		std::cout << GRAY "Phone number: " GREEN;
		std::getline(std::cin, phone);
		std::cout << RES;
		if (std::cin.eof()) {
			std::cout << RED "EOF received" RES << std::endl;
			std::exit(1);
		}
		phone = initPhoneNumber(phone);
		if (!phone.empty()) {
			break ;
		}
		std::cout << _ERR "Invalid phone number" RES << std::endl;
	}

	while (secret.empty()) {
		std::cout << GRAY "Darkest secret: " GREEN;
		std::getline(std::cin, secret);
		std::cout << RES;
		if (std::cin.eof()) {
			std::cout << RED "EOF received" RES << std::endl;
			std::exit(1);
		}
		secret = initMessage(secret);
		if (!secret.empty()) {
			break ;
		}
		std::cout << _ERR "Invalid secret" RES << std::endl;
	}

	return Contact(first, last, nick, phone, secret);
}
