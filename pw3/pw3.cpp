#include <iostream>
#include <list>
using namespace std;

//declare hardcoded list on top
list<int> myNumbers = {9, 13, 4, 12, 11, 6};


void removeFromList(int &x) {
    for (int number : list<int>(myNumbers)) {
        double calculate = (double)number / (double)x;
        if (calculate == (int)calculate) { //if calculate returns integer, then divisible true, else false. If its integer, it is divisible, if its not integer, then its obviously not divisible.
            myNumbers.remove(number);
        }
    }
}


int main() {
    int input;

    cout << "initial list numbers:" << endl;
    for (int numbers : myNumbers) {
        cout << numbers << endl;
    }

    cout << "enter any number - only numbers from the given list that are not divisible by input number will remain in the list" << endl;
    cout << "all numbers that are divisible by input number will be removed from the list" << endl;
    cin >> input;

    if (input == 0) { //safecheck against dividing by zero
        cout << "division by zero not allowed" << endl;
        return 1;
    }

    removeFromList(input);
    cout << "final list after removeFromList() function run:" << endl;
    for (int numbers : myNumbers) {
        cout << numbers << endl;
    }

    return 0;
}