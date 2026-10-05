#include <iostream>
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

int sum(int &n, int &m) {
    int squareN = squareNumber(n);
    int squareM = squareNumber(m);
    return squareN + squareM;
}

int main() {
    int n, m;
    input(n, m);
    if (!numberCanBeSquared(n) || !numberCanBeSquared(m)) {
        cout << "input violation: one of input numbers cannot be squared" << endl;
        return 0;
    }
    int sumResult = sum(n, m);
    cout << "first number: " << n << " second number: " << m << endl;
    cout << "sum of two numbers: " << sumResult << endl;
    return 0;
}