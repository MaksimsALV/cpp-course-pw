#include <iostream>
#include <list>
#include <string>
#include <random>
#include "Contact.h" //separate file for Contact class . for readability and code management
using namespace std;

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

int main() {
  Contact contact = addContact();

  cout << contact.getId() << " " << contact.getFirstName() << " " << contact.getLastName() << " " << contact.getEmail() << " " << contact.getPhoneNumber() << endl;

  return 0;
}