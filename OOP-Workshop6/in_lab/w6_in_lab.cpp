// OOP244 Workshop 6 in_lab
// File w6_in_lab.cpp
// Date 2017-02-21
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca

#include <iostream>
#include "Contact.h"

using namespace std;
using namespace communication;

int main()
{
	cout << "----------------------------------------" << endl;
	cout << "Testing the default constructor!" << endl;
	cout << "----------------------------------------" << endl;
	communication::Contact empty;
	empty.display();
	cout << "----------------------------------------" << endl << endl;

	cout << "----------------------------------------" << endl;
	cout << "Testing an invalid contact!" << endl;
	cout << "----------------------------------------" << endl;
	Contact bad(nullptr, nullptr, 0);
	bad.display();
	Contact alsoBad("", nullptr, 0);
	alsoBad.display();
	cout << "----------------------------------------" << endl << endl;

	cout << "----------------------------------------" << endl;
	cout << "Testing the constructor with parameters!" << endl;
	cout << "----------------------------------------" << endl;
	Contact temp("A contact with a very looooong name!", nullptr, 0);
	temp.display();
	cout << "----------------------------------------" << endl << endl;

	cout << "----------------------------------------" << endl;
	cout << "Testing a valid contact!" << endl;
	cout << "----------------------------------------" << endl;
	long long phoneNumbers[] = { 1416123456, 14161234567, 1416234567890, 14162345678, -1, 124163456789};
	Contact someContact("John Doe", phoneNumbers, 6);
	someContact.display();
	cout << "----------------------------------------" << endl << endl;

	return 0;
}
