//main
#include "student.h"
#include "softwareStudent.h"
#include "Degreetype.h"
#include "roster.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <sstream>


using namespace std;
int main()
{
	Roster classRoster;
	const int arrQuan = 3;
	const string studatTable[5] =
	{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,Security",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,Network",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,Software",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,Security",
	"A5,Sean,Pharris,spharri@wgu.edu,27,45,45,45,Software",
	};
	std::cout << "                 Scripting and Programming -- Applications                " << endl;
	std::cout << "                              Sean Pharris                                " << endl;
	std::cout << "                          Student ID:001307124                            " << endl;
	std::cout << "                      Programming Language used: C++                      " << endl << endl << endl << endl;
	std::cout << "--------------------------------------------------------------------------" << endl;
	std::cout << "                            Student Data Table:                           " << endl;
	std::cout << "--------------------------------------------------------------------------" << endl;

	string delimiter = ",";
	for (int i = 0; i < 5; ++i) {
		vector<string> inputVctr;
		cout << studatTable[i] << endl;
		string stuDat = studatTable[i];
		string studDiff = "";
		int position = 0;
		while (stuDat.length() > 0) {
			int position = stuDat.find(delimiter);
			studDiff = stuDat.substr(0, position);
			inputVctr.push_back(studDiff);
			if (position != string::npos) {
				stuDat.erase(0, (position + 1));
			}
			else {
				stuDat.erase(0, stuDat.length());
			}
		}
		int inputAge = stoi(inputVctr.at(4));
		int inputdays[3];
		string inputstuID = inputVctr.at(0);
		string inputfName = inputVctr.at(1);
		string inputlName = inputVctr.at(2);
		string inputEmail = inputVctr.at(3);
		for (int x = 0; x < 3; ++x) {
			int tempInt = stoi(inputVctr.at(x + 5));
			inputdays[x] = tempInt;
		}
		string lookatDegreetype = inputVctr.at(8);

		Degreetype inputDegreetype{};
		if (lookatDegreetype == "Software") {
			inputDegreetype = Software;
		}
		if (lookatDegreetype == "Networking") {
			inputDegreetype = Networking;
		}
		if (lookatDegreetype == "Security") {
			inputDegreetype = Security;
		}
		classRoster.add(
			inputstuID, 
			inputfName, 
			inputlName, 
			inputEmail, 
			inputAge, 
			inputdays, 
			arrQuan, 
			inputDegreetype);
	}
	cout << "--------------------------------------------------------------------------" << endl;
	classRoster.printAll();
	classRoster.printInvalidEmails();
	cout << "--------------------------------------------------------------------------" << endl;
	for (int x = 0; x < classRoster.gettypeStudent(); ++x) {
		string stuID = classRoster.classrosArr[x]->getstuID();
		cout << "Student ID: " << stuID << "   ";
		classRoster.printDaysInCourse(stuID);
	}
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "Software Students: " << endl;
	classRoster.printByDegreetype(static_cast<int>(Software));
	classRoster.remove("A3");
	classRoster.remove("A3");
	return 0;
}
Roster::Roster() {
	return;
}

Roster::~Roster() {
	delete classrosArr;
	return;
}
void Roster::add(
	string stuID, 
	string fName, 
	string lName, 
	string email, 
	int age, 
	int days[], 
	int arrQuan, 
	Degreetype 
	degreetype) {

	if (degreetype == Software) {
		classrosArr[typeStudent] = new softStudent(
			stuID, 
			fName, 
			lName, 
			email, 
			age, 
			days, 
			arrQuan, 
			degreetype);
		++typeStudent;
	}
	if (degreetype == Networking) {
		classrosArr[typeStudent] = new netStudent(
			stuID, 
			fName, 
			lName, 
			email, 
			age, 
			days, 
			arrQuan, 
			degreetype);
		++typeStudent;
	}
	if (degreetype == Security) {
		classrosArr[typeStudent] = new secStudent(
			stuID, 
			fName, 
			lName, 
			email, 
			age, 
			days, 
			arrQuan, 
			degreetype);
		++typeStudent;
	}
	return;
}
void Roster::printAll() {
	for (int i = 0; i < typeStudent; ++i) {
		classrosArr[i]->print();
	}
	return;
}
void Roster::printDaysInCourse(string stuID) {
	for (int x = 0; x < typeStudent; ++x) {
	string checkVal = classrosArr[x]->getstuID();
	if (checkVal == stuID) {
	int totDay = 0;
	int avg = 0;
	for (int y = 0; y < 3; ++y) {
				totDay += classrosArr[x]->getdays()[y];
			}
			avg = totDay / 3;
			cout << "Averaged Amount of days to complete each course: " << avg << endl;
		}
		else {};
	}
	return;
}
void Roster::printInvalidEmails() {
	for (int i = 0; i < typeStudent; ++i) {
		string checkVal = classrosArr[i]->getEmail();
		char dotError = checkVal.find('.');
		char spaceError = checkVal.find(' ');
		char atsignError = checkVal.find('@');
		if (dotError == string::npos || atsignError == string::npos || spaceError != string::npos) {
			cout << "Invalid Email:" << checkVal << endl;
		}
		else {};
	}
}
int Roster::gettypeStudent() {
	return typeStudent;
}
void Roster::printByDegreetype(int degreetype) {
	for (int x = 0; x < typeStudent; ++x) {
	if (static_cast<int>(classrosArr[x]->getDegreeProgram()) == degreetype) {
	classrosArr[x]->print();
		}
		else {};
	}
}
void Roster::remove(string stuID) {
	bool checkFlag = false;
	for (int x = 0; x < typeStudent; ++x) {
	if (classrosArr[x]->getstuID() == stuID) {
	for (int y = x; y < (typeStudent - 1); ++y) {
				classrosArr[y] = classrosArr[y + 1];
			}
			checkFlag = true;
			typeStudent = 1;
			cout << stuID << " Removed" << endl;
		}
	}
	if (checkFlag == false) {
		cout << "Student not found." << endl;
	}
}
