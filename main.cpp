#include <iostream>
#include <string>
#include "student.h"
#include "roster.h"
using namespace std;


int main() {

	const int numStudents = 5;

	//add studentData[] from task scenario into main function
	const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
			"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
			"A3,Jack,Napoli,The_lawyear99yahoo.com,19,20,40,33,SOFTWARE",
			"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
			"A5,Janet,Wilson,jwi3390@wgu.edu,32,30,40,35,SOFTWARE" };

	//print course title, programming language, student ID, and name
	cout << "C867 Scripting and Programming Applications" << endl;
	cout << "Programming Language: C++" << endl;
	cout << "WGU Student ID: 003953633" << endl;
	cout << "Name: Janet Wilson" << endl;
	cout << endl;


	//create an instance of a roster
	Roster classRoster;


	int i;
	for (i = 0; i < size(studentData); ++i) {
		classRoster.parse(studentData[i]);
	}

	//call printall
	classRoster.printAll();
	cout << endl;

	//Display invalid emails
	cout << "Displaying invalid emails: " << endl;
	cout << endl;
	classRoster.printInvalidEmails();

	cout << endl;

	//print average days in course
	for (int i = 0; i < numStudents; ++i) {
		string studentID = classRoster.classRosterArray[i]->GetstudentID();
		cout << "Student ID: " << studentID << ", ";
		cout << "average days in course is ";
		classRoster.printAverageDaysInCourse(studentID);
	}
	cout << endl;

	//print by degreeprogram
	classRoster.printDegreeByProgram(DegreeProgram::SOFTWARE);

	cout << endl;

	//remove student A3
	classRoster.remove("A3");

	cout << endl;

	//print All to see if A3 was removed
	classRoster.printAll();

	cout << endl;

	//Attempt to print A3 to see if remove function works correctly
	classRoster.remove("A3");




	return 0;

}

