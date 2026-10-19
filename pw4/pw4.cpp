#include <iostream>
#include <cmath>
using namespace std;

class Triangle {
  double sideA;
  double sideB;
  double sideC;

  public:
    Triangle(double a, double b, double c) { //constructor
      sideA = a;
      sideB = b;
      sideC = c;
    }

    ~Triangle() { //destructor
      cout << "object is destroyed" << endl;
    }

  void change(double ca, double cb, double cc) { //alter
    sideA += ca;
    sideB += cb;
    sideC += cc;
  }

  void printLengths() { //print lengths of sides
    cout << sideA << ", " << sideB << ", " << sideC << endl;
  }

  double calculatePerimeter() { //function helper for perimeter
    double perimeter = sideA + sideB + sideC;
    return perimeter;
  }

  double calculateArea() { //function helper for area, using heron area formula
    double s = calculatePerimeter() / 2;
    double area = sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
    return area;
  }

  double calculateMaxAlt() { //function helper for max alt
    double shortestSide = sideA;
    if (sideB < shortestSide) {
      shortestSide = sideB;
    }
    if (sideC < shortestSide) {
      shortestSide = sideC;
    }
    double maxAlt = 2 * calculateArea() / shortestSide;
    return maxAlt;
  }

  void printCalculations() {
    cout << "Perimeter: " << calculatePerimeter() << endl;
    cout << "area: " << calculateArea() << endl;
    cout << "Max Alt: " << calculateMaxAlt() << endl;
  }
};

int main() {
  double sideA;
  double sideB;
  double sideC;

  cout << "input three triangle sides one by one" << endl;
  cout << "input side A of triangle: ";
  cin >> sideA;
  cout << "input side B of triangle: ";
  cin >> sideB;
  cout << "input side C of triangle: ";
  cin >> sideC;

  Triangle triangle(sideA, sideB, sideC);
  cout << "your entered triangle values: " << endl;
  triangle.printLengths();

  cout << "calculations: " << endl;
  triangle.printCalculations();

  cout << "Now alter three triangle sides one by one" << endl;
  cout << "input side A of triangle: ";
  cin >> sideA;
  cout << "input side B of triangle: ";
  cin >> sideB;
  cout << "input side C of triangle: ";
  cin >> sideC;
  triangle.change(sideA, sideB, sideC);

  cout << "your entered triangle values: " << endl;
  triangle.printLengths();

  cout << "calculations: " << endl;
  triangle.printCalculations();

  return 0;
}