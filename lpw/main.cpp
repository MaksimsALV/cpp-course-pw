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
void exportContactsToCsv(list<Contact> contactsBook);

int main() {
  //todo menu wip
  // {
  //   int choice;
  //   //print main menu here, then->
  //   do {
  //     cout << "type: ";
  //     cin >> choice;
  //     switch (choice) {
  //       case 1: cout << "menu 1 opened" << endl; //open menu 1 here
  //         break;
  //       case 2: cout << "menu 2 opened" << endl; //open menu 2 here
  //         break;
  //     }
  //     if (choice == 0 || choice > 3) {
  //       cout << "restricted input";
  //     }
  //   }
  //   while (choice != 3);
  //
  //   return 0;
  //todo menu wip end


  list<Contact> contactsBook;
  for (int i = 0; i < 1; i++) { //enter 5 contacts in a row
    Contact contact = addContact();
    contactsBook.push_back(contact);
  }

  for (Contact contact : contactsBook) {
    cout <<
      contact.getId() << " " <<
      contact.getUniqueId() << " " <<
      contact.getFirstName() << " " <<
      contact.getLastName() << " " <<
      contact.getEmail() << " " <<
      contact.getPhoneNumber() << " " <<
      contact.getDateCreated() << endl;
  }

  exportContactsToCsv(contactsBook); //testing saving all contacts to csv using new methodhelper

  return 0;
}