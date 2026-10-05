#include <iostream>
using namespace std;

//business logic
bool letterIsInApprovedRange(string l) {
    return l >= "a" && l <= "h";
}

bool numberIsInApprovedRange(int n) {
    return n >= 1 && n <= 8;
}

bool invalidInput(string l, int n) {
    return !letterIsInApprovedRange(l) || !numberIsInApprovedRange(n);
}

void consoleInput(string &l, int &n) { //passing by reference, so my main method knows it. did not work without &
    cout << "insert letter: ";
    cin >> l;
    cout << "insert number: ";
    cin >> n;
}

int calculatePossibleMoves(int n, string l) {
    if (n == 8) {
        return 0;
    }
    int moveForward = (n <= 2 ? 2 : 1); //if n<= 2 we move two steps forward, else we just do 1
    int captures = ((l != "a") && (l != "h")) ? 2 : 1; //a and h rows have only 1 capture option, else two
    return moveForward + captures;
}

//proc
int main () {
    string l = "";
    int n = 0;

    while (true) {
        consoleInput(l, n);

        while (invalidInput(l, n)) {
            cout << "Invalid input, try again" << endl;
            cout << "\n";

            consoleInput(l, n);
        }

        cout << "available moves for white pawn: " << calculatePossibleMoves(n, l) << endl;
        cout << "\n";
        cout << "lets play again" << endl;
    }
}