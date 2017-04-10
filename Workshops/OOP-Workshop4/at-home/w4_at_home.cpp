#include <iostream>
#include "passenger.h"

using namespace std;
using namespace holiday;

int main()
{
	Passenger travellers[] = {
		Passenger(nullptr, "Toronto", 2018, 4, 20),
		Passenger("", "Toronto", 2018, 4, 20),
		Passenger("John Smith", nullptr, 2018, 4, 20),
		Passenger("John Smith", "", 2018, 4, 20),
		Passenger("John Smith", "Toronto", 2018, 4, 20), // valid
		Passenger("John Smith", "Toronto", 2028, 4, 20),
		Passenger("John Smith", "Toronto", 2014, 4, 20),
		Passenger("John Smith", "Toronto", 2020, 12, 31), // valid
		Passenger("John Smith", "Toronto", 2018, 40, 20),
		Passenger("John Smith", "Toronto", 2018, 0, 20),
		Passenger("John Smith", "Toronto", 2017, 1, 1), // valid
		Passenger("John Smith", "Toronto", 2018, 4, 0),
		Passenger("John Smith", "Toronto", 2018, 4, 32),
		Passenger(nullptr, nullptr, 0, 0, 0),
		Passenger()
	};
	cout << "----------------------------------------" << endl;
	cout << "Testing the validation logic" << endl;
	cout << "(only passengers 5, 8 and 11 should be valid)" << endl;
	cout << "----------------------------------------" << endl;
	for (unsigned int i = 0; i < 15; ++i)
	{
		cout << "Passenger " << i + 1 << ": " << (travellers[i].isEmpty() ? "not valid" : "valid") << endl;
	}
	cout << "----------------------------------------" << endl << endl;

	Passenger david("David", "Toronto", 2018, 4, 20);
	Passenger friends[] = {
		Passenger("Vanessa", "Toronto", 2018, 4, 20),
		Passenger("John", "Toronto", 2018, 4, 20),
		Passenger("Alice", "Toronto", 2018, 4, 20),
		Passenger("Bob", "Paris", 2018, 1, 20),
		Passenger("Jennifer", "Toronto", 2018, 4, 20),
		Passenger("Mike", "Toronto", 2018, 4, 20),
		Passenger("Sarah", "Toronto", 2018, 4, 20)
	};

	cout << "----------------------------------------" << endl;
	cout << "Testing the display function" << endl;
	cout << "----------------------------------------" << endl;
	for (int i = 0; i < 4; ++i)
		friends[i].display();
	cout << "----------------------------------------" << endl << endl;

	cout << "----------------------------------------" << endl;
	cout << "Testing the travelWith(...) function." << endl;
	cout << "----------------------------------------" << endl;
	david.travelWith(nullptr, 0);
	david = Passenger("Ross", "Toronto", 2018, 4, 20);
	david.travelWith(friends, 3);
	david = Passenger("Isabela", "Toronto", 2018, 4, 20);
	david.travelWith(friends, 7);
	cout << "----------------------------------------" << endl << endl;


	return 0;
}
