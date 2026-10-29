//
// Created by user on 27-Oct-26.
//

#include <iostream>
#include <string>
#include <chrono>
#include "Contact.h"
using namespace std;
using namespace std::chrono;

string generateUniqueId(); //declaring so that addContact() func can reach it for id
string generateDateCreated();

Contact addContact() { //helper func for adding contact to the Contact obj
    string id = generateUniqueId();
    string firstName;
    string lastName;
    string email;
    string phoneNumber;
    string dateCreated = generateDateCreated();

    cin >> firstName >> lastName >> email >> phoneNumber;
    return Contact(id, firstName, lastName, email, phoneNumber, dateCreated);
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

string generateDateCreated() {
    const auto currentTime = system_clock::now();
    const time_t currentTimeClock = system_clock::to_time_t(currentTime);
    return ctime(&currentTimeClock);
}
