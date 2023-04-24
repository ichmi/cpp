#include "PhoneBook.hpp"

int main() {
	PhoneBook   phoneBook;
	std::string operation;

	while (true) {
		std::cout << GRAY 
		"Would you like to " YELLOW "ADD" GRAY "(" YELLOW "1" GRAY ") a new contact, "
		YELLOW "SEARCH" GRAY "(" YELLOW "2" GRAY ") for "
		"or " YELLOW "EXIT" GRAY "(" YELLOW "3" GRAY ")? " CYAN;

		std::getline(std::cin, operation);
		std::cout << RES;
		if (std::cin.eof()) {
			std::cout << RED "\nEOF received" RES << std::endl;
			return 1;
		}

		if (operation == "EXIT" || operation == "3") {
			return 0;
		}

		if (operation.empty()) {
			continue ;
		}

		if (operation == "ADD" || operation == "1") {
			phoneBook.add(Contact::create());
			std::cout << _ACC GRAY "New contact inserted in Phonebook" RES << std::endl << std::endl;
		} else if (operation == "SEARCH" || operation == "2") {
			if (phoneBook.getSize() == 0) {
				std::cout << _WAR GRAY "List of contacts is empty" RES << std::endl << std::endl;
				continue ;
			}
			phoneBook.search();

			std::cout << GRAY "Enter a contact index to display its info: " CYAN;
			std::string indexStr;
			std::getline(std::cin, indexStr);
			std::cout << RES;
			if (std::cin.eof()) {
				std::cout << RED "\nEOF received" RES << std::endl;
				return 1;
			}

			if (phoneBook.displayInfo(indexStr)) {
				continue ;
			}
		} else {
			std::cout << _ERR GRAY "Invalid option" RES << std::endl << std::endl;
		}
	}

	return 0;
}
