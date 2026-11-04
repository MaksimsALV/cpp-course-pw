#include <iostream>
#include <list>
#include <string>
#include "Contact.h" //separate file for Contact class . for readability and code management
using namespace std;

//declares
Contact createContact();
void exportContactsToCsv(list<Contact> contactsBook);
void removeContact(list<Contact>& contactBook, int id);
void updateContact(list<Contact>& contactsBook, int id, string firstName, string lastName, string email, string phoneNumber);

int main() {
  list<Contact> contactsBook;
  for (int i = 0; i < 2; i++) { //enter 5 contacts in a row
    Contact contact = createContact();
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
      contact.getDateCreated() << " " <<
      contact.getDateUpdated() << endl;
  }

  //testing contact removal logic
  removeContact(contactsBook, 1);

  for (Contact contact : contactsBook) {
    cout << "remove check" <<
      contact.getId() << " " <<
      contact.getUniqueId() << " " <<
      contact.getFirstName() << " " <<
      contact.getLastName() << " " <<
      contact.getEmail() << " " <<
      contact.getPhoneNumber() << " " <<
      contact.getDateCreated() << " " <<
      contact.getDateUpdated() << endl;
  }

  //testing update contact logic
  updateContact(contactsBook, 2, "Maksis", "", "", "");

  for (Contact contact : contactsBook) {
    cout << "update check" <<
      contact.getId() << " " <<
      contact.getUniqueId() << " " <<
      contact.getFirstName() << " " <<
      contact.getLastName() << " " <<
      contact.getEmail() << " " <<
      contact.getPhoneNumber() << " " <<
      contact.getDateCreated() << " " <<
      contact.getDateUpdated() << endl;
  }

  exportContactsToCsv(contactsBook); //testing saving all contacts to csv using new methodhelper

  return 0;
}