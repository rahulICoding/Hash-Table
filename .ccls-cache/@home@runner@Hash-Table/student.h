//Rahul Iyer
#pragma once
#include <iostream>

using namespace std;

class Student {
 public:
  Student(char*, char*, int, float);
  void set_first_name(char*);
  void set_last_name(char*);
  void set_id(int);
  void set_gpa(float);
  char* getFirstName();
  char* getLastName();
  int getId();
  float getGpa();

  char firstName[20];
  char lastName[20];
  int studentID;
  float gpa;
};