#include "degree.h"
#include <string>
#include <iostream>
using namespace std;


class Student {


public:
	const static int sizeOfArray = 3;

	//Create accessor for each instance variable from part D1
	string GetstudentID();
	string GetfirstName();
	string GetlastName();
	string GetemailAddress();
	int Getage();
	int* GetnumDays();
	DegreeProgram GetdegreeProgram();

	//Create mutator for each instance variable from part D1
	void SetstudentID(string studentID);
	void SetfirstName(string firstName);
	void SetlastName(string lastName);
	void SetemailAddress(string emailAddress);
	void Setage(int age);
	void SetnumDays(int numDays[]);
	void SetdegreeProgram(DegreeProgram degreeProgram);

	//6d Constructor
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numDays[], DegreeProgram degreeProgram);

	//6e add print function
	void print();



private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int numDays[sizeOfArray];
	DegreeProgram degreeProgram;

};
