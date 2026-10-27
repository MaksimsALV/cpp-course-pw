//
// Created by user on 27-Oct-26.
//
#ifndef CPP_COURSE_LAB_WORKS_UNIQUEIDGENERATOR_H
#define CPP_COURSE_LAB_WORKS_UNIQUEIDGENERATOR_H

#endif //CPP_COURSE_LAB_WORKS_UNIQUEIDGENERATOR_H

#include <string>
using namespace std;

string generateUniqueId() {
    const string CHARACTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    string uniqueId;
    srand(time(0)); //rand() func needs it, else its not random
    for (int i = 0; i < 15; i++) { //for every loop iteration take random char from CHARACTERS string to the uniqueId string
        uniqueId += CHARACTERS[rand() % CHARACTERS.length()];
    }
    return uniqueId;
}