#include <iostream>
#include <list>
#include <string>
#include <random>
using namespace std;

class Contact {
private:
  string id;
  string firstName;
  string lastName;
  string email;
  string phoneNumber;

public:
  Contact(string id, string firstName, string lastName, string email, string phoneNumber) { //constructor because of private
    this->id = id;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->phoneNumber = phoneNumber;
  }

  //getters
  string getId() {
    return id;
  };
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

// class ContactBook {
// private:
//   int id;
//
// public:
//   ContactBook() {
//     this->id = id;
//   }
//
//   int getId() {
//     return id;
//   };
// };

string generateUniqueId() {
  const string CHARACTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
  string uniqueId;
  srand(time(0)); //rand() func needs it, else its not random
  for (int i = 0; i < 15; i++) { //for every loop iteration take random char from CHARACTERS string to the uniqueId string
    uniqueId += CHARACTERS[rand() % CHARACTERS.length()];
  }
  return uniqueId;
}

Contact addContact() { //helper func for adding contact to the Contact obj
  string id = generateUniqueId();
  string firstName;
  string lastName;
  string email;
  string phoneNumber;

  cin >> firstName >> lastName >> email >> phoneNumber;
  return Contact(id, firstName, lastName, email, phoneNumber);
}

//large project work - course project - hello world
int main() {
  Contact contact = addContact();

  cout << contact.getId() << " " << contact.getFirstName() << " " << contact.getLastName() << " " << contact.getEmail() << " " << contact.getPhoneNumber() << endl;

  return 0;
}