#include "PhoneBook.hpp"

int main() {
  PhoneBook phone_book;
  std::string operation;

  while (true) {
    std::cout << "Would you like to ADD (1) a new contact, SEARCH (2) for a contact, or EXIT (3)? ";
    std::getline(std::cin, operation);

    if (operation == "EXIT" || operation == "3") {
      return 0;
    }
    if (operation.empty()) {
      continue ;
    }
    if (operation == "ADD" || operation == "1") {
      phone_book.add(Contact::create());
      std::cout << _ACEPT << "New contact inserted in Phonebook" << std::endl << std::endl;
    } else if (operation == "SEARCH" || operation == "2") {
      if (phone_book.getSize() == 0) {
        std::cout << "List of contacts is empty" << std::endl << std::endl;
        continue ;
      }
      phone_book.search();
    } else {
      std::cout << _ERROR << "Invalid option" << std::endl << std::endl;
    }
  }
  return 0;
}
