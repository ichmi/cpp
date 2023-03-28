#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _size(0), _oldest(0) {}

void PhoneBook::add(Contact contact) {
    if (_size == _MAX_CONTACT) {
        if (_oldest == _MAX_CONTACT) {
            _oldest = 0;
        }
        _contacts[_oldest] = contact;
        _oldest++;
        return;
    }

    int i = 0;
    while (_contacts[i]) {
        i++;
    }
    _contacts[i] = contact;
    _size++;
}

int PhoneBook::getSize() const {
    return _size;
}

const Contact* PhoneBook::getContacts() const {
    return static_cast<const Contact *>(this->_contacts);
}

void PhoneBook::search() const {
    std::cout << std::endl;
    std::string title = BLUE " CONTACTS " RES;
    std::string separator = "=";
    const int tableSize = 17;

    for (int i=0; i < tableSize; i++) { std::cout << separator; }
    std::cout << title;
    for (int i=0; i < tableSize; i++) { std::cout << separator; }
    std::cout << std::endl;

    std::cout << YELLOW << "  INDEX   " << RES << "| ";
    std::cout << YELLOW << "  FIRST  " << RES << "| ";
    std::cout << YELLOW << "  LAST   " << RES << "| ";
    std::cout << YELLOW << "  NICK  " << RES;
    std::cout << std::endl;
    std::cout << std::setw(11) << std::setfill('-') << "+";
    std::cout << std::setw(11) << std::setfill('-') << "+";
    std::cout << std::setw(11) << std::setfill('-') << "+";
    std::cout << std::setw(12) << std::setfill('-') << " ";
    std::cout << std::endl;

    for (int i = 0; i < this->_size; i++) {
        std::cout
        << std::setw(10) << std::setfill(' ') << i << "|"
        << std::setw(10) << std::setfill(' ') << truncateStr(this->_contacts[i].getFirst()) << "|"
        << std::setw(10) << std::setfill(' ') << truncateStr(this->_contacts[i].getLast()) << "|"
        << std::setw(10) << std::setfill(' ') << truncateStr(this->_contacts[i].getNick())
        << std::endl;
    }
    std::cout << std::endl;
}
