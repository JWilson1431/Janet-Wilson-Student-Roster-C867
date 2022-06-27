#include <iostream>
#include <string>
using namespace std;

class Roster {


public:
	void parse(string row);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int numDays1, int numDays2, int numDays3, DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printDegreeByProgram(DegreeProgram degreeProgram);
	Roster();
	~Roster();

	//create an array of pointers to hold the data provided in the StudentData table
	Student* classRosterArray[5];
	int numStudent = 5;
	int studentCount = 0;
	int i;

};

