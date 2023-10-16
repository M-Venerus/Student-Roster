#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#ifndef roster_h
#define roster_h
#include "degree.h"
#include "student.h"
using std::string;


static const unsigned int STUDENTS = 5;


class Roster {
public:

	// Pointer for array created with num of student elements, null value.
	Student* classRosterArray[STUDENTS] = { nullptr, nullptr, nullptr, nullptr, nullptr };


	void Add(string studentID, string studentFirstName, string studentLastName, string studentEmail, int studentAge,
		int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeType);
	void ClassRosterResolve(string record);
	void Remove(string studentID);
	void PrintAll();
	void PrintAvgDaysInCourse(string studentID);
	void PrintInvalidEmails();
	void PrintByDegreeProgram(DegreeProgram degreeType);

	// Roster Destructor
	~Roster();


private:

	// Increment num used for adding students to classRosterArray
	int increment = -1;
};



#endif