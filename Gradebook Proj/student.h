#pragma once
#include "Degreetype.h"
#include <iostream>
#include <string>

using namespace std;

class Student {
public:
	Student(
		string stuID, 
		string fName, 
		string lName, 
		string email, 
		int age, 
		int days[], 
		int arrQuan, 
		Degreetype degreetype);
	Student();
	~Student();
public:
	string getstuID(); 
	string getfName(); 
	string getlName(); 
	string getEmail(); 
	int getAge(); 
	int* getdays();
public:
	void setstuID(string stuID);
	void setfName(string fName);
	void setlName(string lName);
	void setEmail(string email);
	void setAge(int age);
	void setdays(int days[], int arrQuan);
public:
	virtual void print() {
		return;
	};
public:
	virtual Degreetype getDegreeProgram() {
		return degreetype;
	};
protected:
	string stuID;
	string fName;
	string lName;
	string email;
	int age;
	int days[3];
protected:
	Degreetype degreetype;
};