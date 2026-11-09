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
void mainMenuNavigation();
void menuActionAddContact(list<Contact>& contactsBook);
void menuActionUpdateContact(list<Contact>& contactsBook);
void menuActionRemoveContact(list<Contact>& contactsBook);
void menuActionViewContacts(list<Contact>& contactsBook);
void menuActionExportContacts(list<Contact>& contactsBook);

int main() {
  list<Contact> contactsBook;
  int choice;

  do {
    mainMenuNavigation();

    cin >> choice;

    switch (choice) {
      case 1: { //add
        menuActionAddContact(contactsBook);
        break;
      }
      case 2: { //update
        menuActionUpdateContact(contactsBook);
        break;
      }
      case 3: { //remove
        menuActionRemoveContact(contactsBook);
        break;
      }
      case 4: { //view
        menuActionViewContacts(contactsBook);
        break;
      }
      case 5: { //export
        menuActionExportContacts(contactsBook);
        break;
      }
      case 0: { //quit
        cout << "Exiting program..." << endl;
        return 0;
      }
    }
  } while (choice != 0);
  return 0;
}