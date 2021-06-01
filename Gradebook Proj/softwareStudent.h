#pragma once
#include "roster.h"
#include "Degreetype.h"
#include "student.h"
#include <string>
#include <iostream>
using namespace std;

class softStudent : public Student {
public:
	softStudent(
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
	~softStudent();
	void print();
public:
	Degreetype getDegreeProgram();

};
