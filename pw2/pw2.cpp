#include <iostream>
#include <cmath>
using namespace std;

void input(int &n, int &m) {
    cout << "insert first number: " << endl;
    cin >> n;
    cout << "insert second number: " << endl;
    cin >> m;
}

bool numberCanBeSquared(int n) {
    return n >= 0;
}

int squareNumber(int n) {
    return n * n;
}

int sumOfTwoSquareNumbers(int a, int b) {
    return squareNumber(a) + squareNumber(b);
}

int main() {
    int n, m;
    input(n, m);

    if (!numberCanBeSquared(n) || !numberCanBeSquared(m)) {
        cout << "input violation: one of input numbers cannot be squared" << endl;
        return 0;
    }

    if (n > m) {
        cout << "input violation: first number cannot be larger than second" << endl;
        return 0;
    }

    for (int x = n; x <= m; x++) { //loops through all numbers in range between og n<>m
        for (int a = 1; squareNumber(a) < x; a++) { // this to ensure a^2 stays smaller than x, so that x - a^2 later remains valid for sqrt()
            int b = round(sqrt(x - squareNumber(a))); //getting integer back here. round() just to roundup as a safenet against some wierd non integer values
            if (sumOfTwoSquareNumbers(a, b) == x) {
                cout << x << " ";
                break;
            }
        }
    }

    return 0;
}