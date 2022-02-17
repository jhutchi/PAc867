#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"

using std::string;
using std::cout;
using std::endl;

class Student {
public:
	const static int daysInCourse = 3;
private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	string age;
	int finishDate[daysInCourse];
	DegProgram degProgram;

public:
	//constructors
	Student();//no parameters - sets to default values so object creation is possible
	Student(string studentID, string firstName, string lastName, string email, string age, int finishDate[], DegProgram degProgram);
	~Student();//destructor
	
	//getters
	string getID();
	string getFirst();
	string getLast();
	string getEmail();
	string getAge();
	const int* getDays();//no array notation
	DegProgram getDegProgram();

	//setters
	void setID(string studentID);
	void setFirst(string firstName);
	void setLast(string lastName);
	void setEmail(string email);
	void setAge(string age);
	void setDays(int finishDate[]);
	void setDegProgram(DegProgram degProgram);

	static void header();
	void print();//display student data
};
