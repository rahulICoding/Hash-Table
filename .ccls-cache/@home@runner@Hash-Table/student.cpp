//Rahul Iyer
#include <iostream>
#include "student.h"
#include <cstring>

using namespace std;

Student::Student(char* firstName, char* lastName, int studentID, float gpa) {
  strncpy(this->firstName, firstName, 19);
  strncpy(this->lastName, lastName, 19);
  this->studentID = studentID;
  this->gpa = gpa;
}

void Student::set_first_name(char* first1) {
  strcpy(firstName, first1);
}

void Student::set_last_name(char* last1) {
  strcpy(lastName, last1);
}

void Student::set_id(int studentid1) {
  studentID = studentid1;
}

void Student::set_gpa(float gpa1) {
  gpa = gpa1;
}

char* Student::getFirstName() {
  return firstName;
}

char* Student::getLastName() {
  return lastName;
}

int Student::getId() {
  return studentID;
}

float Student::getGpa() {
  return gpa;
}