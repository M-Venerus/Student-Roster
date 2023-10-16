#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
using std::string;
#ifndef student_h
#define student_h
#include "degree.h"


// Student Class created soley to create objects.
class Student {
public:

	// Create Student class constructors
	Student();
	Student(string studentID, string studentFirstName, string studentLastName, string studentEmail,
		int studentAge, int numDays[], DegreeProgram degreeType);

	// Mutator/Setter functions
	void setStudentId(string studentID);
	void setStudentFirstName(string studentFirstName);
	void setStudentLastName(string studentLastName);
	void setStudentEmail(string studentEmail);
	void setStudentAge(int studentAge);
	void setStudentNumDaysInCourse(int numDays[]);
	void setStudentDegreeProgram(DegreeProgram degreeType);

	// Accessor/Getter functions
	string getStudentId() const;
	string getStudentFirstName() const;
	string getStudentLastName() const;
	string getStudentEmail() const;
	int getStudentAge() const;
	int* getStudentNumDaysInCourse() const;
	DegreeProgram getStudentDegreeProgram();
	void Print();


private:

	// Student Class variables
	string studentID;
	string studentFirstName;
	string studentLastName;
	string studentEmail;
	int studentAge;
	int* numDays;
	DegreeProgram degreeType;

	// Set constant number of courses a student takes
	const int COURSES = 3;
};

#endif