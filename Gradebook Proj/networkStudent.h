#pragma once
#include "student.h"
#include "roster.h"
#include "Degreetype.h"
#include <string>
#include <iostream>

using namespace std;

class netStudent : public Student {
public:
	netStudent(
		string stuID, 
		string fName, 
		string lName, 
		string email, 
		int age, 
		int days[], 
		int arrQuan, 
		Degreetype degreetype)
		: Student(
			stuID, 
			fName, 
			lName, 
			email, 
			age, 
			days, 
			arrQuan, 
			degreetype) {
		return;
	}
	~netStudent();
	void print();
public:
	Degreetype getDegreeProgram();


};

