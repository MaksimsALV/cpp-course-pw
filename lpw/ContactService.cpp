//
// Created by user on 27-Oct-26.
//

#include <iostream>
#include <string>
#include <chrono> //https://en.cppreference.com/cpp/chrono
#include "Contact.h"
using namespace std;
using namespace std::chrono;

string generateUniqueId(); //declaring so that addContact() func can reach it for id
string generateDateCreated();

Contact addContact() { //helper func for adding contact to the Contact obj
    string uniqueId = generateUniqueId();
    string firstName;
    string lastName;
    string email;
    string phoneNumber;
    string dateCreated = generateDateCreated();

    cin >> firstName >> lastName >> email >> phoneNumber;
    return Contact(uniqueId, firstName, lastName, email, phoneNumber, dateCreated);
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
    auto now = system_clock::to_time_t(system_clock::now()); //https://en.cppreference.com/cpp/chrono

    stringstream ss;
    ss << put_time(localtime(&now), "%Y-%m-%d_%H-%M-%S"); //stringstream and put_time func allows to format date and time string https://en.cppreference.com/cpp/io/manip/put_time
    return ss.str(); //returns string
}