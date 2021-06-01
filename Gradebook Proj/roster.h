#pragma once
#include "Degreetype.h"
#include "student.h"
#include "softwareStudent.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include <string>
#include <iostream>

using namespace std;

class Roster {
public:
	void add(
		string stuID, 
		string fName, 
		string lName, 
		string email, 
		int age, 
		int days[], 
		int arrQuan, 
		Degreetype 
		Degreetype);
	void remove(string stuID);
	void printAll();
	void printDaysInCourse(string stuID);
	void printInvalidEmails();
	void printByDegreetype(int Degreetype);
	int gettypeStudent();
	Roster();
	~Roster();

	Student *classrosArr[5];
private:
	int typeStudent = 0;
};
