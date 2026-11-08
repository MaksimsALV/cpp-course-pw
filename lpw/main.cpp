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

  int choice;

  do {
    cout << "\n" << endl;
    cout << "Enter 1 to add new contact" << endl;
    cout << "Enter 2 to update new contact" << endl;
    cout << "Enter 3 to remove new contact" << endl;
    cout << "Enter 4 to view all contacts" << endl;
    cout << "Enter 5 to export all contacts into CSV" << endl;
    cout << "Enter 0 to quit the program" << endl;

    cin >> choice;

    switch (choice) {
      case 1: {
        Contact contact = createContact();
        contactsBook.push_back(contact);
        cout << "Contact added" << endl;
        break;
      }
      case 2: {
        int id;
        string firstName, lastName, email, phoneNumber;
        cout << "Enter id of contact you want to update: ";
        cin >> id;
        cout << "Enter first name or empty press enter: ";
        cin >> firstName;
        cout << "Enter last name or empty press enter: ";
        cin >> lastName;
        cout << "Enter email or empty press enter: ";
        cin >> email;
        cout << "Enter phone number or empty press enter: ";
        cin >> phoneNumber;
        updateContact(contactsBook, id, firstName, lastName, email, phoneNumber);
        cout << "Contact updated" << endl;
        break;
      }
      case 3: {
        int id;
        cout << "Enter id of contact you want to remove" << endl;
        cin >> id;
        removeContact(contactsBook, id);
        cout << "Contact removed" << endl;
        break;
      }
      case 4: {
        if (contactsBook.empty()) {
          cout << "Contacts book is empty" << endl;
        } else {
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
        }
        break;
      }
      case 5: {
        if (contactsBook.empty()) {
          cout << "Contacts book is empty" << endl;
        } else {
          cout << "Export all contacts into CSV..." << endl;
          exportContactsToCsv(contactsBook);
          cout << "Export all contacts into CSV complete" << endl;
          break;
        }
      }
      case 0: {
        cout << "Exiting program..." << endl;
        return 0;
      }
    }
  } while (choice != 0);
  return 0;
}