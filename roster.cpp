#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "roster.h"
#include "degree.h"
#include "student.h"

using std::string;

// Create student objects and add to classRosterArray
void Roster::Add(string studentID, string studentFirstName, string studentLastName, string studentEmail,
				 int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeType) {
	int numDays[] = {daysInCourse1, daysInCourse2, daysInCourse3};


	// Incrementally add student objects
	classRosterArray[++increment] = new Student(studentID, studentFirstName, studentLastName, studentEmail, studentAge, numDays, degreeType);
}

// Parsing of student data
void Roster::ClassRosterResolve(string studentDataRecord) {
	std::vector<string> tempData;
	DegreeProgram studentDegree;
	for (int i = 0; i < STUDENTS; ++i) {
		std::stringstream ss(studentDataRecord);
		
		while (ss.good()) {
			string subStr;
			std::getline(ss, subStr, ',');
			tempData.push_back(subStr);
		}
		
		if (tempData[8] == "SECURITY") {
			studentDegree = DegreeProgram::SECURITY;
		}
		if (tempData[8] == "NETWORK") {
			studentDegree = DegreeProgram::NETWORK;
		}
		if (tempData[8] == "SOFTWARE") {
			studentDegree = DegreeProgram::SOFTWARE;
		}
	}
	Roster::Add(tempData.at(0), tempData.at(1), tempData.at(2), tempData.at(3), stoi(tempData.at(4)), stoi(tempData.at(5)),
				stoi(tempData.at(6)), stoi(tempData.at(7)), studentDegree);
}


// Remove student record with studentID input
void Roster::Remove(string studentID) {
	std::cout << "Removing record for student " << studentID << "." << std::endl;
	for (int i = 0; i < STUDENTS; ++i) {
		if (classRosterArray[i] == nullptr) {
			std::cout << "Student " << studentID << " not found." << std::endl;
			break;
		}
		// Assign nullptr to replace student record
		else if (studentID == classRosterArray[i]->Student::getStudentId()) {
			classRosterArray[i] = nullptr;
			std::cout << "Student " << studentID << " record removed." << std::endl;
		}
	}
	std::cout << std::endl << std::endl;
}


// Print all student data
void Roster::PrintAll() {
	for (int i = 0; i < STUDENTS; ++i) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->Student::Print();
		}
	}
	std::cout << std::endl << std::endl;
}


// Takes studentID input, retrieves numDays array and averages the days, then outputs that avg
void Roster::PrintAvgDaysInCourse(string studentID) {
	for (int i = 0; i < STUDENTS; ++i) {
		if (studentID == classRosterArray[i]->Student::getStudentId()) {
			int* daysPerCourse = classRosterArray[i]->getStudentNumDaysInCourse();
			std::cout << studentID << "'s average: ";
			int avgDays = (daysPerCourse[0] + daysPerCourse[1] + daysPerCourse[2]) / 3;
			std::cout << avgDays << std::endl;
		}
	}
}


// Prints emails that are invalid
void Roster::PrintInvalidEmails() {
	for (int i = 0; i < STUDENTS; ++i) {
		bool emailValid = false;
		string email = "";
		email = classRosterArray[i]->Student::getStudentEmail();
		if ((email.find("@") != string::npos) && (email.find(".") != string::npos)) {
			emailValid = true;
		}
		if (email.find(" ") != string::npos) {
			emailValid = false;
		}
		if (emailValid == false) {
			std::cout << classRosterArray[i]->Student::getStudentEmail() << std::endl;
		}
	}
	std::cout << std::endl << std::endl;
}


// Print by degree type
void Roster::PrintByDegreeProgram(DegreeProgram degreeType) {
	string degreeString = "";
	if (degreeType == DegreeProgram::SECURITY) {
		degreeString = "Security";
	}
	else if (degreeType == DegreeProgram::NETWORK) {
		degreeString = "Network";
	}
	else if (degreeType == DegreeProgram::SOFTWARE) {
		degreeString = "Software";
	}
	else
		degreeString = "Error/Unknown";
	std::cout << std::endl << "Printing students studying the " << degreeString << " degree program:" << std::endl << std::endl;
	
	for (int i = 0; i < STUDENTS; ++i) {
		if (classRosterArray[i] != nullptr) {
			if (degreeType == classRosterArray[i]->Student::getStudentDegreeProgram()) {
				classRosterArray[i]->Student::Print();
			}
		}
	}
	std::cout << std::endl << std::endl;
}


// Destructor implemented to release memory
Roster::~Roster() {
	for (int i = 0; i < STUDENTS; ++i) {
		delete classRosterArray[i];
		(classRosterArray[i] = nullptr);
	}
}