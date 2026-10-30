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
    const auto now = system_clock::now();
    const time_t currentTimeClock = system_clock::to_time_t(now);
    stringstream ss;
    ss << put_time(localtime(&currentTimeClock), "%Y%m%d_%H%M%S"); //with help of AI had to format the timestamp into string format for other usages. Previously used ctime, and since it returned char not string, couldnt reuse it for CsvService rapidcsv filename saving
    return ss.str(); //returns string
}
