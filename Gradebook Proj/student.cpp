#include "student.h"
#include "degreetype.h"
#include <string>

using namespace std;

Student::Student(
	string stuID, 
	string fName, 
	string lName, 
	string email, 
	int age, 
	int days[], 
	int arrQuan, 
	Degreetype degreetype) {
		this->stuID = stuID, 
		this->fName = fName, 
		this->lName = lName, 
		this->email = email, 
		this->age = age;
	for (int x = 0; x < 3; ++x) {
this->days[x] = days[x];
	}
	this->degreetype = degreetype;
}
Student::Student() {
	return;
}
Student::~Student() {
	return;
}
string Student::getstuID() {
	return stuID;
}
string Student::getfName() {
	return fName;
}
string Student::getlName() {
	return lName;
}
string Student::getEmail() {
	return email;
}
int Student::getAge() {
	return age;
}
int* Student::getdays() {
	return days;
}
void Student::setstuID(string stuID) {
	this->stuID = stuID;
}
void Student::setfName(string fName) {
	this->fName = fName;
}
void Student::setlName(string lName) {
	this->lName = lName;
}
void Student::setEmail(string email) {
	this->email = email;
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::setdays(int days[], int arrQuan) {
	for (int x = 0; x < arrQuan; ++x) {
		this->days[x] = days[x];
	}
}