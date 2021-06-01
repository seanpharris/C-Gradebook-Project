#include "student.h"
#include "networkStudent.h"
#include "roster.h"
#include "Degreetype.h"
#include <string>
#include <iostream>

using namespace std;

netStudent::~netStudent() {
	return;
}
Degreetype netStudent::getDegreeProgram() {
	return degreetype;
}
void netStudent::print() {
	std::cout << "Student ID: " << getstuID() << endl;
	std::cout << "First Name: " << getfName() << endl;
	std::cout << "Last Name: " << getlName() << endl;
	std::cout << "Email: " << getEmail() << endl;
	std::cout << "Age: " << getAge() << endl;
	std::cout << "Amount of days to complete each course: ";
	for (int i = 0; i < 3; ++i) {
		cout << getdays()[i] << " ";
	}
	std::cout << endl;
	string addDegreetype;
	if (getDegreeProgram() == Security) {
		addDegreetype = "Security";
	}
	if (getDegreeProgram() == Software) {
		addDegreetype = "Software";
	}
	if (getDegreeProgram() == Networking) {
		addDegreetype = "Networking";
	}
	std::cout << "Degree: " << addDegreetype << endl << "--------------------------------------------------------------------------" << endl;
	return;
}