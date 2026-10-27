//
// Created by user on 27-Oct-26.
//
#ifndef CPP_COURSE_LAB_WORKS_CONTACT_H
#define CPP_COURSE_LAB_WORKS_CONTACT_H

#endif //CPP_COURSE_LAB_WORKS_CONTACT_H

#include <string>
#include "tools/UniqueIdGenerator.h"
using namespace std;

string generateUniqueId(); //declaring so that addContact() func can reach it for id

class Contact {
private:
    string id;
    string firstName;
    string lastName;
    string email;
    string phoneNumber;

public:
    Contact(string id, string firstName, string lastName, string email, string phoneNumber) { //constructor because of private
        this->id = id;
        this->firstName = firstName;
        this->lastName = lastName;
        this->email = email;
        this->phoneNumber = phoneNumber;
    }

    //getters
    string getId() {
        return id;
    };
    string getFirstName() {
        return firstName;
    };
    string getLastName() {
        return lastName;
    };
    string getEmail() {
        return email;
    };
    string getPhoneNumber() {
        return phoneNumber;
    };

};

Contact addContact() { //helper func for adding contact to the Contact obj
    string id = generateUniqueId();
    string firstName;
    string lastName;
    string email;
    string phoneNumber;

    cin >> firstName >> lastName >> email >> phoneNumber;
    return Contact(id, firstName, lastName, email, phoneNumber);
}