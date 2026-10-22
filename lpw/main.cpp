#include <iostream>
#include <list>
#include <string>
using namespace std;

class Contact {
private:
  string firstName;
  string lastName;
  string email;
  string phoneNumber;

public:
  Contact(string firstName, string lastName, string email, string phoneNumber) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->phoneNumber = phoneNumber;
  }

  string getFirstName() {
    return firstName;
  };
  string getLastName() {
    return lastName;
  };
  string getEmail() {
    return email;
  };
  string getPhoneNumber() {
    return phoneNumber;
  };

};

//large project work - course project - hello world
int main() {
  Contact contact("abc", "abcc", "email", "phone");
  cout << contact.getFirstName() << " " << contact.getLastName() << endl;

  return 0;
}