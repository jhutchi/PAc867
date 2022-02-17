#include "roster.h"
#include <cstring>

void Roster::parse(string studentData) {
	DegProgram dp = DegProgram::SOFTWARE;
	//overload 
	if (studentData.back() == 'K') dp = DegProgram::NETWORK;	//only choice ending in 'K'
	if (studentData.back() == 'Y') dp = DegProgram::SECURITY;	//only choice ending in 'K'

	int rhs = studentData.find(",");	//right hand side
	string sID = studentData.substr(0, rhs);	//studentID
	int lhs = rhs + 1;					//left hand side - reset

	rhs = studentData.find(",", lhs);	//moves to next comma
	string sFirst = studentData.substr(lhs, rhs - lhs);
	lhs = rhs + 1;

	rhs = studentData.find(",", lhs);
	string sLast = studentData.substr(lhs, rhs - lhs);
	lhs = rhs + 1;

	rhs = studentData.find(",", lhs);
	string sEmail = studentData.substr(lhs, rhs - lhs);
	lhs = rhs + 1;

	rhs = studentData.find(",", lhs);
	string sAge = studentData.substr(lhs, rhs - lhs);

	int daysInCourse[3];//array bc easier to loop, though slower

	for (int i = 0; i < 3; i++) {
		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		daysInCourse[i] = std::stoi(studentData.substr(lhs, rhs - lhs));//stoi converts to int
	}
	add(sID, sFirst, sLast, sEmail, sAge, (daysInCourse[0]), (daysInCourse[1]), (daysInCourse[2]), dp);
}

void Roster::add(string studentID, string firstName, string lastName, string email,	string age,
	int daysInCourse1, int daysInCourse2, int daysInCourse3, DegProgram degProgram)
{
	int studentarr[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, email, age, studentarr, degProgram);
}

void Roster::printAll() {
	Student::header();
	for (int i = 0; i <= Roster::lastIndex; i++)
		Roster::classRosterArray[i]->print();

	/*{
		cout << classRosterArray[i]->getID();
		cout << '\t';
		cout << classRosterArray[i]->getFirst();
		cout << '\t';
		cout << classRosterArray[i]->getLast();
		cout << '\t';
		cout << classRosterArray[i]->getEmail();
		cout << '\t';
		cout << classRosterArray[i]->getAge();
		cout << '\t';
		cout << classRosterArray[i]->getFinish()[0];
		cout << '\t';
		cout << classRosterArray[i]->getFinish()[1];
		cout << '\t';
		cout << classRosterArray[i]->getFinish()[2];
		cout << '\t';
		cout << degTypeStrings[classRosterArray[i]->getDegProgram()] << endl;
	}*/
}

void Roster::printByDegProg(DegProgram degProgram) {
	Student::header();
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegProgram() == degProgram) classRosterArray[i]->print();
	}
	cout << endl;
}

void Roster::printInvalidEmail() {
			//missing space, missing @, or missing period
	for (int i = 0; i <= Roster::lastIndex; i++) {
		string sEmail = (classRosterArray[i]->getID());
		if (sEmail.find(' ') == string::npos || (sEmail.find('@') != string::npos || sEmail.find('.') != string::npos)) {
			cout << sEmail << " is invalid" << endl;
		}
		else
			cout << "None" << endl;
	} 
	
}

void Roster::printAverageDays(string studentID) {
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->getID() == studentID) {
			cout << studentID << ":";
			cout << (classRosterArray[i]->getDays()[0] +
				classRosterArray[i]->getDays()[1] +
				classRosterArray[i]->getDays()[2]) / 3 << endl;
		}
	}
}

void Roster::removeStudentByID(string studentID) {
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->getID() == studentID) {
			success = true;
			Student* temp = classRosterArray[i];
			classRosterArray[i] = classRosterArray[numStudents - 1];
			classRosterArray[numStudents - 1] = temp;
			Roster::lastIndex--;	//decrement lastIndex and removed student should be invisible
		}
	}
	if (success) {
		cout << "Student " << studentID << " removed." << endl;
		printAll();	//removed student should not display
	}
	else
		cout << "Student " << studentID << " not found." << endl;
}
Roster::~Roster() {
	for (int i = 0; i < numStudents; i++) {
		cout << "Removing student" << i + 1 << endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}
