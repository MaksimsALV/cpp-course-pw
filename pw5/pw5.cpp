#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int lettersCounter(string text) { //function helper for counting lettersand ignoring given symbls
  int count = 0;
  for (char c : text) {
    if (c != ','
    && c != '.'
    && c != '('
    && c != ')'
    && c != '!'
    && c != '?') {
      count++;
    }
  }
  return count;
}

int main() {
  ofstream write;
  fstream read;
  string file = "f.txt";
  string dummyText = "Hello! My name is Bill.";
  string content;
  int numb[5] = {0};//initialization on all elementss to 0 , to  avoid garbage values. this also needed for line 56 numb[number]++ to count correctly
  int number;

  write.open(file, ios::app);

  if (!write) { //appeding text to file
    cout << "no file found.";
  } else {
    write << dummyText;
    cout << dummyText << " <-- this text has been appended to file successfully." << endl;
    write.close();
  }

  read.open(file);

  cout << "this is the file content: "; //reading text in file
  while (read >> content) {
    cout << content << " ";
  }
  read.close();

  read.open(file);
  write.open("f1.txt"); //we write length and count in a new file,after reading from first file
  cout << "this is how many letters long every found word is: " << endl;
  write << "Length\tCount" << endl;

  while (read >> content) {
    number = lettersCounter(content);
    numb[number]++;
  }
  read.close();
  write.close();

  write.open("f1.txt");
  write << "Length\tCount" << endl;
  for (int len = 1; len <= 5; len++) {
    write << len << "\t" << numb[len] << endl;
  }
  write.close();

  read.open("f1.txt");
  while (getline(read, content)) {
    cout << content << endl;
  }
  read.close();


  return 0;
}