#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _size(0), _oldest(0) {}

void PhoneBook::add(Contact contact) {
    if (_size == _MAX_CONTACT) {
        if (_oldest == _MAX_CONTACT) {
            _oldest = 0;
        }
        _contacts[_oldest] = contact;
        _oldest++;
        return ;
    }

    int i = 0;
    while (_contacts[i]) {
        i++;
    }
    _contacts[i] = contact;
    _size++;
}

int PhoneBook::getSize(void) const {
    return _size;
}

const Contact* PhoneBook::getContacts(void) const {
    return static_cast<const Contact *>(this->_contacts);
}

void PhoneBook::search(void) const {
    std::cout << std::endl;
    std::string title = BLUE " CONTACTS " RES;
    std::string separator = "=";
    const int tableSize = 17;

    for (int i=0; i < tableSize; i++) {
        std::cout << separator;
    }
    std::cout << title;
    for (int i=0; i < tableSize; i++) {
        std::cout << separator;
    }
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

int PhoneBook::displayInfo(std::string const &indexStr) const {
    std::istringstream iss(indexStr);
    int index;
    iss >> index;
    if (iss.fail() || index < 0) {
        std::cout << RED "Invalid index" RES << std::endl << std::endl;;
        return 1;
    }

    if (index >= this->getSize()) {
        std::cout << RED "Contact not found" RES << std::endl << std::endl;
        return 1;
    }

    Contact contact = this->getContacts()[index];

    std::cout << GRAY "First name:     " YELLOW << contact.getFirst() << RES << std::endl;
    std::cout << GRAY "Last name:      " YELLOW << contact.getLast() << RES << std::endl;
    std::cout << GRAY "Nickname:       " YELLOW << contact.getNick() << RES << std::endl;
    std::cout << GRAY "Phone number:   " YELLOW << contact.getPhone() << RES << std::endl;
    std::cout << GRAY "Darkest secret: " YELLOW << contact.getSecret() << RES << std::endl;
    std::cout << std::endl;

    return 0;
}
