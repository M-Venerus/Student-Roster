#include <iostream>
#include "student.h"
using std::string;

// Initiallizing a Student object
Student::Student(string studentID, string studentFirstName, string studentLastName, string studentEmail,
	int studentAge, int numDays[], DegreeProgram degreeType) {
	setStudentId(studentID);
	setStudentFirstName(studentFirstName);
	setStudentLastName(studentLastName);
	setStudentEmail(studentEmail);
	setStudentAge(studentAge);
	setStudentNumDaysInCourse(numDays);
	setStudentDegreeProgram(degreeType);
}

// Initiallizing a blank Student record
Student::Student() : studentID(""), studentFirstName(""), studentLastName(""), studentEmail(""),
studentAge(-1), numDays(new int[COURSES]) {
	// Set each course day value to 0
	for (int i = 0; i < COURSES; ++i) {
		this->numDays[i] = 0;
	}
}

// Mutator/Setter function definitions
void Student::setStudentId(string studentID)					{this->studentID = studentID;}
void Student::setStudentFirstName(string studentFirstName)		{this->studentFirstName = studentFirstName;}
void Student::setStudentLastName(string studentLastName)		{this->studentLastName = studentLastName;}
void Student::setStudentEmail(string studentEmail)				{this->studentEmail = studentEmail;}
void Student::setStudentAge(int studentAge)						{this->studentAge = studentAge;}
void Student::setStudentDegreeProgram(DegreeProgram degreeType) {this->degreeType = degreeType;}
// Iterate through courses
void Student::setStudentNumDaysInCourse(int numDays[])		    {this->numDays = new int[COURSES];
	for (int i = 0; i < COURSES; ++i) {
		this->numDays[i] = numDays[i];
	}
}

// Accessor/Getter function definitions
string Student::getStudentId() const				{return studentID;}
string Student::getStudentFirstName() const			{return studentFirstName;}
string Student::getStudentLastName() const			{return studentLastName;}
string Student::getStudentEmail() const				{return studentEmail;}
int Student::getStudentAge() const					{return studentAge;}
int* Student::getStudentNumDaysInCourse() const		{return numDays;}
DegreeProgram Student::getStudentDegreeProgram()	{return degreeType;}

// Print all student variables
void Student::Print() {
	// Get days in courses
	int* days = getStudentNumDaysInCourse();
	
	//Print student info
	std::cout << "Student ID: " << getStudentId() << "\t";
	std::cout << "First Name: " << getStudentFirstName() << "\t";
	std::cout << "Last Name: " << getStudentLastName() << "\t";
	std::cout << "Email Address: " << getStudentEmail() << "\t";
	string tempEmail = getStudentEmail();
	if (tempEmail.length() <= 15) {
		std::cout << "\t";
	}
	std::cout << "Age: " << getStudentAge() << "\t";
	
	// Print days for each course
	std::cout << "Number of Days in Courses: ";
	for (int i = 0; i < COURSES; ++i) {std::cout << days[i] << " ";}
	std::cout << "\t";
	
	// Print degree type for student info printing
	string degreeString = "";
	if ((getStudentDegreeProgram()) == DegreeProgram::SECURITY) {
		degreeString = "Security";
	}
	else if ((getStudentDegreeProgram()) == DegreeProgram::NETWORK) {
		degreeString = "Network";
	}
	else if ((getStudentDegreeProgram()) == DegreeProgram::SOFTWARE) {
		degreeString = "Software";
	}
	else
		degreeString = "Error/Unknown";
	std::cout << "Degree Program: " << degreeString << std::endl;
}
