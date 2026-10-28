#include <iostream>
#include <list>
#include <string>
#include "Contact.h" //separate file for Contact class . for readability and code management
using namespace std;

// class ContactBook {
// private:
//   int id;
//
// public:
//   ContactBook() {
//     this->id = id;
//   }
//
//   int getId() {
//     return id;
//   };
// };
Contact addContact(); //declare so that it can be reached

int main() {
  list<Contact> contactsBook;
  for (int i = 0; i < 2; i++) {
    Contact contact = addContact();
    contactsBook.push_back(contact);
    i++;
  }
  // Contact contact = addContact();
  // contactsBook.push_back(contact);

  // cout << contact.getId() << " " << contact.getFirstName() << " " << contact.getLastName() << " " << contact.getEmail() << " " << contact.getPhoneNumber() << endl;
  for (Contact contact : contactsBook) {
    cout << contact.getId() << " " << contact.getFirstName() << " " << contact.getLastName() << " " << contact.getEmail() << " " << contact.getPhoneNumber() << endl;
  }
  return 0;
}