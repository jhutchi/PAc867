#include <iostream>
#include "roster.h"


int main() {

	//student data table
	cout << "C867, C++, studentID: 001374855, Jonathan Hutchinson" << endl;
	const string studentData[] = {

		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",

		"A5,Jonathan,Hutchinson,jhut138@wgu.edu,27,30,30,30,SOFTWARE"
	};

	const int numStudents = 5;
	Roster roster;
	
	for (int i = 0; i < numStudents; i++)roster.parse(studentData[i]);
		cout << "Printing students: " << endl;
		roster.printAll();	//pass in size of array
		cout << endl;

	for (int i = 0; i < 3; i++) {
		cout << "Printing by degree type: " << degTypeStrings[i] << endl;
		roster.printByDegProg((DegProgram)i);	
	}
	
	cout << "Printing students with invalid emails" << endl;
	roster.printInvalidEmail();
	cout << endl;

	cout << "Printing average days left in class for each student: " << endl;
	for (int i=0;i<numStudents; i++)
		roster.printAverageDays(roster.classRosterArray[i]->getID());
		
	
	cout << "Removing student with ID: A3" << endl;
	roster.removeStudentByID("A3");
	cout << "Student removed" << endl;


	cout << endl;

	system("pause");
	return 0;
}
