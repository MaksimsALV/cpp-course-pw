//
// Created by user on 09-Nov-26.
//

#include <iostream>
#include <list>
#include <string>
#include "Contact.h"

//declares
Contact createContact();
void exportContactsToCsv(list<Contact> contactsBook);
void removeContact(list<Contact>& contactBook, int id);
void updateContact(list<Contact>& contactsBook, int id, string firstName, string lastName, string email, string phoneNumber);

void mainMenuNavigation() {
    cout << "\n" << endl;
    cout << "Enter 1 to add new contact" << endl;
    cout << "Enter 2 to update new contact" << endl;
    cout << "Enter 3 to remove new contact" << endl;
    cout << "Enter 4 to view all contacts" << endl;
    cout << "Enter 5 to export all contacts into CSV" << endl;
    cout << "Enter 0 to quit the program" << endl;
}

void menuActionAddContact(list<Contact>& contactsBook) {
    Contact contact = createContact();
    contactsBook.push_back(contact);
    cout << "Contact added" << endl;
}

void menuActionUpdateContact(list<Contact>& contactsBook) {
    int id;
    string firstName, lastName, email, phoneNumber;

    if (contactsBook.empty()) {
        cout << "Contacts book is empty" << endl;
        return;
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
}

void menuActionRemoveContact(list<Contact>& contactsBook) {
    int id;

    if (contactsBook.empty()) {
        cout << "Contacts book is empty" << endl;
        return;
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

    cout << "Enter id of contact you want to remove" << endl;
    cin >> id;
    removeContact(contactsBook, id);
    cout << "Contact removed" << endl;
}

void menuActionViewContacts(list<Contact>& contactsBook) {
    if (contactsBook.empty()) {
        cout << "Contacts book is empty" << endl;
        return;
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
}

void menuActionExportContacts(list<Contact>& contactsBook) {
    if (contactsBook.empty()) {
        cout << "Contacts book is empty" << endl;
        return;
    } else {
        cout << "Export all contacts into CSV..." << endl;
        exportContactsToCsv(contactsBook);
        cout << "Export all contacts into CSV complete" << endl;
    }
}