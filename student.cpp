#include "student.h"

Student::Student() {	//setting fields to default values
	this->studentID = "";//empty string vs nullptr
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = "";
	for (int i = 0; i < daysInCourse; i++)
		this->finishDate[i] = 0;
	this->degProgram = DegProgram::SOFTWARE;
}

Student::Student(string studentID, string firstName, string lastName, string email, string age, int finishDate[], DegProgram degProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < daysInCourse; i++)
		this->finishDate[i] = finishDate[i];
	this->degProgram = degProgram;
}

Student::~Student() {}//destr 

//getters
string Student::getID() { return this->studentID; }
string Student::getFirst() { return this->firstName; }
string Student::getLast() { return this->lastName; }
string Student::getEmail() { return this->email; }
string Student::getAge() { return this->age; }
const int* Student::getDays() { return this->finishDate; }
DegProgram Student::getDegProgram() { return this->degProgram; }

//setters
void Student::setID(string ID) { this->studentID = ID; }
void Student::setFirst(string firstName) { this->firstName = firstName; }
void Student::setLast(string lastName) { this->lastName = lastName; }
void Student::setEmail(string email) { this->email = email; }
void Student::setAge(string age) { this->age = age; }
void Student::setDays(int finishDate[]){		//each date must be set individually
	for (int i = 0; i < daysInCourse; i++)this->finishDate[i] = finishDate[i];
}
void Student::setDegProgram(DegProgram dp) { this->degProgram = degProgram; }


void Student::header() {
	//tab separated 
	cout << "Student ID\t";
	cout << "First Name\t";
	cout << "Last Name\t";
	cout << "Email Address\t";
	cout << "Age\t";
	cout << "Days in Course 1\t";
	cout << "Days in Course 2\t";
	cout << "Days in Course 3\t";
	cout << "Degree Program\t";
	cout << endl;
}

void Student::print() {
	//tab separated 
	cout << this->getID() << '\t';
	cout << this->getFirst() << '\t';
	cout << this->getLast() << '\t';
	cout << this->getEmail() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getDays()[0] << ',';
	cout << this->getDays()[1] << ',';
	cout << this->getDays()[2] << '\t';
	cout << degTypeStrings[(int)this->degProgram];
	cout << endl;
}
