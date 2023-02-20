//Rahul Iyer
//hash table
//adds students and creates a new hash table every time there are more than 3 nodes in it
//feb 19 2023


#include <iostream>
#include <cstring>
#include "student.h"
#include "node.h"

using namespace std;

void reHash(int &tableSize, Node** &hashTable);

int main() {

  int tableSizeInit = 100; //initial size of hash table
  int tableSize = tableSizeInit;
  Node** hashTable = new Node*[tableSize];

  for (int i = 0; i < tableSize; i++) { //set nodes to null -> able to change later on
    hashTable[i] = NULL;
  }

  char input[20];
  bool running = true;

  while(running) {
    cout << "" << endl;
    cout << "Do you want to 'add', 'generate', 'print', 'delete', or 'quit'" << endl;
    cin.get(input, 20);
    cin.ignore(1, '\n');

    if (strcmp("add", input) == 0) { //adding node
      char firstName[20];
      char lastName[20];
      int studentID;
      float gpa;
      Student* newStudent = new     
 Student(firstName, lastName, studentID, gpa);

      cout << "First Name: " << endl;
      cin.get(firstName, 20);
      cin.ignore(1, '\n');
      newStudent->set_first_name(firstName);

      cout << "Last Name: " << endl;
      cin.get(lastName, 20);
      cin.ignore(1, '\n');
      newStudent->set_last_name(lastName);

      cout << "Student ID: " << endl;
      cin >> studentID;
      cin.ignore();
      newStudent->set_id(studentID);

      cout << "GPA: " << endl;
      cin >> gpa;
      cin.ignore();
      newStudent->set_gpa(gpa);

      Node* newNode = new Node(newStudent);

      //find spot in hash table to place student
      int index = newStudent->getId() % tableSize;

      if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
      }
      else { //if more nodes in that spot add to next
        Node* current = hashTable[index];
        while (current->getNext() != NULL) {
          current = current->getNext();
        }
        current->setNext(newNode);
        newNode->setNext(NULL);
      }

      int count;
      for (int i = 0; i < tableSize; i++) { 
        Node* temp = hashTable[i];
        count = 0;
        while (temp != NULL) {
          count++;
          temp = temp->getNext();
          
        }
        if (count > 3) { //if there are more than 3 nodes in the hash index rehash all the students
          reHash(tableSize, hashTable);
        }
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

    else if (strcmp("delete", input) == 0) { //deletes students
      int ID;
      cout << "what student do you want to delete?" << endl;
      cin >> ID;
      cin.ignore();

      int index = ID % tableSize;

      if (hashTable[index] != NULL) {
        Node* current = hashTable[index];
        Node* prev = NULL;
        while (current != NULL) {
          if (current->getStudent()->getId() == ID) {
            if (prev == NULL) { //delete current next
              hashTable[index] = current->getNext();
              delete current;
              break;
            }
            else { //delete prev
              prev->setNext(current->getNext());
              delete current;
              break;
            }
          }
          //set curent to prev and deleet next
          prev = current;
          current = current->getNext();
        }
      }
    }

    else if(strcmp("quit", input) == 0) {
      running = false;
    }
  }
}

void reHash(int &tableSize, Node** &hashTable) { //rehash table
  tableSize = tableSize*2; //increasing size of table

  Node** temp = new Node*[tableSize];
  for (int i = 0; i < tableSize; i++) {
    temp[i] = NULL;
  }

  for (int i = 0; i < tableSize/2; i++) {
    if (hashTable[i] != NULL) {
      Node* current = hashTable[i];
      while (current != NULL) {
        Node* newNode = new Node(current->getStudent());
        int hashIndex = current->getStudent()->getId() % tableSize; //find student and place in new hash table
        if (temp[hashIndex] == NULL) {
          temp[hashIndex] = newNode;
        }
        else if (temp[hashIndex] != NULL) {
          Node* current2 = temp[hashIndex];
          while (current2->getNext() != NULL) { //itereate to find next open spot in hash table
            current2 = current2->getNext();
          }
          current2->setNext(newNode);
        }
        current = current->getNext();
      }
    }
  }
  
}