#include <iostream>
#include <string>
#include "student.h"
using namespace std;


//accessor definitions
string Student::GetstudentID() {
	return studentID;
}

string Student::GetfirstName() {
	return firstName;
}

string Student::GetlastName() {
	return lastName;
}

string Student::GetemailAddress() {
	return emailAddress;

}

int Student::Getage() {
	return age;
}

int* Student::GetnumDays() {
	return numDays;
}

DegreeProgram Student::GetdegreeProgram() {
	return degreeProgram;
}



//mutator definitions

void Student::SetstudentID(string studentID) {
	this->studentID = studentID;
}

void Student::SetfirstName(string firstName) {
	this->firstName = firstName;
}

void Student::SetlastName(string lastName) {
	this->lastName = lastName;
}

void Student::SetemailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}

void Student::Setage(int age) {
	this->age = age;
}

void Student::SetnumDays(int numDays[]) {
	for (int i = 0; i < sizeOfArray; ++i) {
		this->numDays[i] = numDays[i];
	}
}

void Student::SetdegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

//constructor


Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numDays[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < sizeOfArray; ++i) {
		this->numDays[i] = numDays[i];
	}
	this->degreeProgram = degreeProgram;
	return;
}

//define the print function
void Student::print() {
	cout << studentID << '\t';
	cout << "First Name: " << firstName << '\t';
	cout << "Last Name: " << lastName << '\t';
	cout << "Age: " << age << '\t';
	cout << "Days In Course: {" << numDays[0] << ", " << numDays[1] << ", " << numDays[2] << "} ";
	cout << "Degree Program ";
	if (degreeProgram == DegreeProgram::SOFTWARE) {
		cout << "SOFTWARE" << endl;
	}
	if (degreeProgram == DegreeProgram::NETWORK) {
		cout << "NETWORK" << endl;
	}
	if (degreeProgram == DegreeProgram::SECURITY) {
		cout << "SECURITY" << endl;
	}

}
