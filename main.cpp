#include <iostream>

#include "addressbook.h"

int main(int argc, char **argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " COMMAND FILENAME" << endl
         << "COMMAND: 'load' or 'save'" << endl
         << "Load will load the JSON file, FILENAME, and print out its contents." << endl
         << "Save will save a sample address book to FILENAME in JSON format." << endl;
    return 1;
  }
  AddressBook address_book;
  if (argv[1] == "load") {
    address_book = AddressBook::JsonCreate(argv[2]);
  } else if (argv[1] == "save") {
    address_book.AddPerson("Alice", "111-222-3333");
    address_book.AddPerson("Bob", "555-444-3333");
    address_book.JsonSave(argv[2]);
  }
  return 0;
}
