//
// Created by user on 27-Oct-26.
//
#ifndef CPP_COURSE_LAB_WORKS_CONTACT_H
#define CPP_COURSE_LAB_WORKS_CONTACT_H

#endif //CPP_COURSE_LAB_WORKS_CONTACT_H

#include <string>
using namespace std;

class Contact {
private:
    inline static int counter = 0; //without static incremental doesnt grow (stays 1), and without inline static doesnt work..
    int id;
    string uniqueId;
    string firstName;
    string lastName;
    string email;
    string phoneNumber;
    string dateCreated;;

public:
    Contact(string uniqueId, string firstName, string lastName, string email, string phoneNumber, string dateCreated) { //constructor because of private
        this->id = ++counter;
        this->uniqueId = uniqueId;
        this->firstName = firstName;
        this->lastName = lastName;
        this->email = email;
        this->phoneNumber = phoneNumber;
        this->dateCreated = dateCreated;
    }

    //getters
    int getId() {
        return id;
    };
    string getUniqueId() {
        return uniqueId;
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
    string getDateCreated() {
        return dateCreated;
    }
};