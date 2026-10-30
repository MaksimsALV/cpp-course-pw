//
// Created by user on 30-Oct-26.
//
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include "Contact.h"
#include "rapidcsv.h" //https://github.com/d99kris/rapidcsv
using namespace std;

string generateDateCreated(); //declare so csv creation can use timestamp within the file name

void exportContactsToCsv(list<Contact> contactsBook) {
    rapidcsv::Document doc; //creating .csv doc

    //setting up the headers
    doc.SetColumnName(0, "id");
    doc.SetColumnName(1, "uniqueId");
    doc.SetColumnName(2, "firstName");
    doc.SetColumnName(3, "lastName");
    doc.SetColumnName(4, "email");
    doc.SetColumnName(5, "phoneNumber");
    doc.SetColumnName(6, "dateCreated");

    for (Contact contact : contactsBook) {
        vector data = { //by reading their github docs, seems that rapidcsv wants vector. other solutions doesnt seems to work.
            to_string(contact.getId()), //unforch rapidcsv wants the same datatypes, so I have to convert it all to same datatipes. in my case, all are strings except integer Id incremental.
            contact.getUniqueId(),
            contact.getFirstName(),
            contact.getLastName(),
            contact.getEmail(),
            contact.getPhoneNumber(),
            contact.getDateCreated()
          };
        size_t nextRowIdx = doc.GetRowCount(); //cannot use InsertRow if dont define size_t rows ....
        doc.InsertRow(nextRowIdx, data);
    }
    doc.Save("contactsExport_" + generateDateCreated() + ".csv"); //reusage of timestamp creation function
}
