// tyler code
#pragma once
#include <iostream>
#include "student.h"

using namespace std;

class Node {
  public:
  Node* getNext();
  Node(Student*);
  Student* getStudent();
  void setNext(Node*);
  ~Node();

  Student* student;
  Node* next;
};