#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(std::string name, std::string last, std::string nick,
                 std::string phone, std::string secret)
    : _first(name), _last(last), _nick(nick), _phone(phone), _secret(secret) {}

Contact::operator bool() const {
    return this->_first != "" && this->_last != "" && this->_nick != "" && this->_phone != "" &&
           this->_secret != "";
}

std::string Contact::getFirst() const { return _first; }
std::string Contact::getLast() const { return _last; }
std::string Contact::getNick() const { return _nick; }
std::string Contact::getPhone() const { return _phone; }
std::string Contact::getSecret() const { return _secret; }

Contact Contact::create(void) {
  std::string first, last, nick, phone, secret;

  while (first.empty()) {
    std::cout << "First name: ";
    std::getline(std::cin, first);
    first = initName(first);
    if (!first.empty()) {
      break ;
    }
    std::cout << _ERROR << "Invalid first name" << std::endl;
  }

  while (last.empty()) {
    std::cout << "Last name: ";
    std::getline(std::cin, last);
    last = initName(last);
    if (!last.empty()) {
      break ;
    }
    std::cout << _ERROR << "Invalid last name" << std::endl;
  }

  while (nick.empty()) {
    std::cout << "Nickname: ";
    std::getline(std::cin, nick);
    nick = initMessage(nick);
    if (!nick.empty()) {
      break ;
    }
    std::cout << _ERROR << "Invalid nickname" << std::endl;
  }

  while (phone.empty()) {
    std::cout << "Phone number: ";
    std::getline(std::cin, phone);
    phone = initPhoneNumber(phone);
    if (!phone.empty()) {
      break ;
    }
    std::cout << _ERROR << "Invalid phone number" << std::endl;
  }

  while (secret.empty()) {
    std::cout << "Darkest secret: ";
    std::getline(std::cin, secret);
    secret = initMessage(secret);
    if (!secret.empty()) {
      break ;
    }
    std::cout << _ERROR << "Invalid secret" << std::endl;
  }

  return Contact(first, last, nick, phone, secret);
}
