#include <iostream>
#include <cstring>
#include "student.h"
#include "node.h"

using namespace std;

int main() {

  int tableSizeInit = 100;
  int tableSize = tableSizeInit;
  Node** hashTable = new Node*[tableSize];

  for (int i = 0; i < tableSize; i++) { //setting all the nodes in the table to null
    hashTable[i] = NULL;
  }

  char input[20];
  bool running = true;

  while(running) {
    cout << "" << endl;
    cout << "Do you want to 'add', 'generate', 'print', 'delete', or 'quit'" << endl;
    cin.get(input, 20);
    cin.ignore(1, '\n');

    if (strcmp("add", input) == 0) {
      char firstName[20];
      char lastName[20];
      int studentID;
      float gpa;
      Student* newStudent = new Student(firstName, lastName, studentID, gpa);

      cout << "First Name: " << endl;
      cin.get(firstName, 20);
      cin.ignore(1, '\n');
      newStudent->set_first_name(firstName);

      // read in last name
      cout << "Last Name: " << endl;
      cin.get(lastName, 20);
      cin.ignore(1, '\n');
      newStudent->set_last_name(lastName);

      // read in student id
      cout << "Student ID: " << endl;
      cin >> studentID;
      cin.ignore();
      newStudent->set_id(studentID);

      // read in gpa
      cout << "GPA: " << endl;
      cin >> gpa;
      cin.ignore();
      newStudent->set_gpa(gpa);

      Node* newNode = new Node(newStudent);

      int index = newStudent->getId() % tableSize;

      if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
      }
      else {
        Node* current = hashTable[index];
        while (current->getNext() != NULL) {
          current = current->getNext();
        }
        current->setNext(newNode);
        newNode->setNext(NULL);
      }
    }
    
    else if (strcmp("print", input) == 0) { // prints all students inputted
      for (int i = 0; i < tableSize; i++) {
        if (hashTable[i] != NULL) {
          Node* current = hashTable[i];
          while (current != NULL) {
            cout << current->getStudent()->getFirstName() << endl;
            cout << current->getStudent()->getLastName() << endl;
            cout << current->getStudent()->getId() << endl;
            cout << current->getStudent()->getGpa() << endl;
            current = current->getNext();
            cout << "" << endl;
          }
        }
      }  
    }

    else if (strcmp("delete", input) == 0) {
      int ID;
      cout << "what student do you want to delete?" << endl;
      cin >> ID;
      cin.ignore();

      int index = ID % tableSize;

      if (hashTable[index] != NULL) {
        
      }
    }

    
    
  }

  
  }