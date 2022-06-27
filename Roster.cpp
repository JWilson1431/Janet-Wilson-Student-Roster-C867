#include <iostream>
#include <string>
#include "student.h"
#include "roster.h"
using namespace std;

//parse function
void Roster::parse(string row) {
	size_t rhs = row.find(",");
	string studentID = row.substr(0, rhs);

	size_t lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string firstName = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string lastName = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string emailAddress = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int age = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int numDays1 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int numDays2 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int numDays3 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string strdegreeProgram = row.substr(lhs, rhs - lhs);

	DegreeProgram degreeProgram = DegreeProgram::SECURITY;
	if (strdegreeProgram == "SECURITY") {
		degreeProgram = DegreeProgram::SECURITY;
	}

	else if (strdegreeProgram == "NETWORK") {
		degreeProgram = DegreeProgram::NETWORK;
	}

	else if (strdegreeProgram == "SOFTWARE") {
		degreeProgram = DegreeProgram::SOFTWARE;
	}

	add(studentID, firstName, lastName, emailAddress, age, numDays1, numDays2, numDays3, degreeProgram);

}

//add function definition
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int numDays1, int numDays2, int numDays3, DegreeProgram degreeProgram) {
	int numDays[3] = { numDays1, numDays2, numDays3 };
	classRosterArray[studentCount] = new Student(studentID, firstName, lastName, emailAddress, age, numDays, degreeProgram);
	studentCount++;

}
//remove function definition
void Roster::remove(string studentID) {
	bool studentFound = false;
	int i;
	int j;
	for (i = 0; i < numStudent; ++i) {
		if (classRosterArray[i]->GetstudentID() == studentID) {
			for (j = i; j < (numStudent - 1); ++j) {
				classRosterArray[j] = classRosterArray[j + 1];
			}
			studentFound = true;
			numStudent = numStudent - 1;
			cout << "Student " << studentID << " was found and deleted." << endl;
		}
	}
	if (studentFound == false) {
		cout << "Student " << studentID << " was not found." << endl;
	}
}

//print all defintion
void Roster::printAll() {
	for (i = 0; i < numStudent; ++i) {
		classRosterArray[i]->print();

	}
}

//Print average number of days in course defintion
void Roster::printAverageDaysInCourse(string studentID) {

	for (int i = 0; i < numStudent; ++i) {
		if (classRosterArray[i]->GetstudentID() == studentID) {
			int sum = 0;
			int average = 0;
			int j = 0;
			for (j = 0; j < 3; ++j) {
				sum += classRosterArray[i]->GetnumDays()[j];
			}
			average = sum / 3;
			cout << average << endl;
		}
	}
}


//print Invalid email function defintion
void Roster::printInvalidEmails() {
	string email;
	for (i = 0; i < numStudent; ++i) {
		string email = classRosterArray[i]->GetemailAddress();
		if (email.find("@") == string::npos) {
			cout << email << " is invalid." << endl;
		}
		else if (email.find(".") == string::npos) {
			cout << email << " is invalid." << endl;
		}
		else if (email.find(" ") != string::npos) {
			cout << email << " is invalid." << endl;
		}
	}
}

//printDegreeByProgram definition
void Roster::printDegreeByProgram(DegreeProgram degreeProgram) {
	cout << "Showing students in degree program SOFTWARE" << endl;
	for (int i = 0; i < numStudent; ++i) {
		if (classRosterArray[i]->GetdegreeProgram() == degreeProgram) {
			this->classRosterArray[i]->print();
		}
	}
}


Roster::Roster() {
	return;
}
//destructor
Roster::~Roster() {
	delete classRosterArray;
	return;
}
;