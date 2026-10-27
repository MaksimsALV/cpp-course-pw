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
  Contact(string firstName, string lastName, string email, string phoneNumber) { //constructor because of private
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->phoneNumber = phoneNumber;
  }

  //getters
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

Contact addContact() { //helper func for adding contact to the Contact obj
  string firstName;
  string lastName;
  string email;
  string phoneNumber;

  cin >> firstName >> lastName >> email >> phoneNumber;
  return Contact(firstName, lastName, email, phoneNumber);
}

//large project work - course project - hello world
int main() {
  Contact contact = addContact();

  cout << contact.getFirstName() << " " << contact.getLastName() << " " << contact.getEmail() << " " << contact.getPhoneNumber() << endl;

  return 0;
}