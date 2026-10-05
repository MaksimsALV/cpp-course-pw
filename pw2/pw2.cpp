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

    for (int x = n; x <= m; x++) {
        for (int a = 1; squareNumber(a) < x; a++) {
            int b = sqrt(x - squareNumber(a));
            if (sumOfTwoSquareNumbers(a, b) == x) {
                cout << x << " ";
                break;
            }
        }
    }

    return 0;
}