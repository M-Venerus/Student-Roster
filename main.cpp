#include <iostream>
#include "roster.h"
#include "student.h"
#include "degree.h"
using namespace std;


// Main program
int main() {
	// Begin with displaying course and my student info
	cout << "Course: C867 - Scripting and Programming - Applications" << endl;
	cout << "Programmed In: C++" << endl;
	cout << "WGU Student ID: 010949995" << endl;
	cout << "Name: Michael Venerus" << endl << endl << endl;
	cout << "Student Data:" << endl << endl;

	// Create array holding student input data
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Michael,Venerus,mveneru@wgu.edu,30,18,12,39,SOFTWARE" 
	};

	// Create an object of type class type Roster to contain student data
	Roster classRoster;
	for (int i = 0; i < STUDENTS; ++i) {
		classRoster.ClassRosterResolve(studentData[i]);
	}

	// Print all student data
	classRoster.PrintAll();

	// Print invalid emails
	cout << "The following students have invalid email addresses: " << endl << endl;
	classRoster.PrintInvalidEmails();

	// Print average days
	cout << "Students average days for 3 courses: " << endl << endl;
	for (int i = 0; i < STUDENTS; ++i) {
		classRoster.PrintAvgDaysInCourse(classRoster.classRosterArray[i]->Student::getStudentId());
	}
	cout << endl;

	//Print by software degree
	classRoster.PrintByDegreeProgram(DegreeProgram::SOFTWARE);

	// Remove 3rd student, print all student data again, then retest removal of 3rd student
	classRoster.Remove("A3");
	cout << "Updated student data:" << endl << endl;
	classRoster.PrintAll();
	classRoster.Remove("A3");

	// Destructor called to release memory
	classRoster.~Roster();

	return 0;
}