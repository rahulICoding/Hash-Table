//tyler code
#include <iostream>
#include "node.h"
#include "student.h"

using namespace std;

Node::Node(Student* newstudent) {
  student = newstudent;
}

Node* Node::getNext() {
  return next;
}

Student* Node::getStudent() {
  return student;
}

void Node::setNext(Node* newnext) {
  next = newnext;
}

Node::~Node() {
  cout << "Deleting Node" << endl;
}