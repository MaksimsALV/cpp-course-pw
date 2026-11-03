//
// Created by user on 27-Oct-26.
//

#include <iostream>
#include <string>
#include <list>
#include <chrono> //https://en.cppreference.com/cpp/chrono
#include "Contact.h"
using namespace std;
using namespace std::chrono;

string generateUniqueId(); //declaring so that addContact() func can reach it for id
string generateTimestamp();

Contact createContact() { //helper func for adding contact to the Contact obj
    string uniqueId = generateUniqueId();
    string firstName;
    string lastName;
    string email;
    string phoneNumber;
    string dateCreated = generateTimestamp();
    string dateUpdated = generateTimestamp();

    cin >> firstName >> lastName >> email >> phoneNumber;
    return Contact(uniqueId, firstName, lastName, email, phoneNumber, dateCreated, dateUpdated);
}

void removeContact(list<Contact>& contactBook, int id) { //https://www.geeksforgeeks.org/cpp/list-erase-function-in-c-stl/
    for (auto it = contactBook.begin(); it != contactBook.end(); ++it) {
        if (it->getId() == id) { //removing  Contact with matched id and quitting the loop
            contactBook.erase(it);
            break;
        }
    }
}

void updateContact(list<Contact>& contactBook, int id, string firstName, string lastName, string email, string phoneNumber) { //https://www.geeksforgeeks.org/cpp/how-to-replace-an-element-in-a-list-in-cpp/
    for (auto it = contactBook.begin(); it != contactBook.end(); ++it) {
        if (it->getId() == id) {
            //setting new values thanks to my setters in Contact.h. Also using if empty() so that I can pass empty strings to fields I am not tend to update (wanted to do null, but this also works)
            if (!firstName.empty()) {
                it->setFirstName(firstName);
            }
            if (!lastName.empty()) {
                it->setLastName(lastName);
            }
            if (!email.empty()) {
                it->setEmail(email);
            }
            if (!phoneNumber.empty()) {
                it->setPhoneNumber(phoneNumber);
            }
            string dateUpdated = generateTimestamp();
            it->setDateUpdated(dateUpdated);
            break;
        }
    }
}

string generateUniqueId() {
    const string CHARACTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    string uniqueId;
    srand(time(0)); //rand() func needs it, else its not random
    for (int i = 0; i < 15; i++) { //for every loop iteration take random char from CHARACTERS string to the uniqueId string
        uniqueId += CHARACTERS[rand() % CHARACTERS.length()];
    }
    return uniqueId;
}

string generateTimestamp() {
    auto now = system_clock::to_time_t(system_clock::now()); //https://en.cppreference.com/cpp/chrono

    stringstream ss;
    ss << put_time(localtime(&now), "%Y-%m-%d_%H-%M-%S"); //stringstream and put_time func allows to format date and time string https://en.cppreference.com/cpp/io/manip/put_time
    return ss.str(); //returns string
}