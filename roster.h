#pragma once
#include "student.h"
#include <cstring>

class Roster
{
public:
	int lastIndex = -1;//correct starting place is 'nowhere'
	const static int numStudents = 5;//size of array
	Student* classRosterArray[numStudents] = { nullptr,nullptr,nullptr,nullptr,nullptr };

	Roster();//parameterless constructor for roster
	Student getStudent();//2 dereferences required to get to a particular student

	void parse(string row);
	void add(string sID, string sFirst, string sLast, string sEmail, string sAge, int sDays1, int sDays2, int sDays3, DegProgram degProgram);
	void printAll();							// calls print() method - prints all students in the roster
	void printByDegProg(DegProgram degProgram);	//prints only the students with specified degree type
	void printInvalidEmail();						//prints only invalid Email 
	void printAverageDays(string studentID);	//prints average days left for specified student
	void removeStudentByID(string studentID);	//removes specified student from the roster
	~Roster();
};
