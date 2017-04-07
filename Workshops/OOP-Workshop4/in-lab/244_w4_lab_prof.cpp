#include <iostream>
#include "passenger.h"
#include "passenger.h" // this is intentional

using namespace std;
using namespace holiday;

int main()
{
	Passenger travellers[] = {
		Passenger(nullptr, "Toronto"),
		Passenger("", "Toronto"),
		Passenger("John Smith", nullptr),
		Passenger("John Smith", ""),
		Passenger("John Smith", "Toronto"), // valid
		Passenger(nullptr, nullptr),
		Passenger()
	};
	cout << "----------------------------------------" << endl;
	cout << "Testing the validation logic" << endl;
	cout << "(only passenger 5 should be valid)" << endl;
	cout << "----------------------------------------" << endl;
	for (unsigned int i = 0; i < 7; ++i)
	{
		cout << "Passenger " << i + 1 << ": " << (travellers[i].isEmpty() ? "not valid" : "valid") << endl;
	}
	cout << "----------------------------------------" << endl << endl;

	Passenger vanessa("Vanessa", "Paris"),
		      mike("Mike", "Tokyo"),
		      alice("Alice", "Paris");

	cout << "----------------------------------------" << endl;
	cout << "Testing the display function" << endl;
	cout << "----------------------------------------" << endl;
	vanessa.display();
	mike.display();
	alice.display();
	cout << "----------------------------------------" << endl << endl;

	cout << "----------------------------------------" << endl;
	cout << "Testing the travelling together logic" << endl;
	cout << "----------------------------------------" << endl;
	cout << "Can Vanessa and Mike travel together (should be NO)? "
		<< (vanessa.canTravelWith(mike) ? "YES" : "NO") << endl;
	cout << "Can Vanessa and Alice travel together (should be YES)? "
		<< (vanessa.canTravelWith(alice) ? "YES" : "NO") << endl;
	cout << "Can Alice and Vanessa travel together (should be YES)? "
		<< (alice.canTravelWith(vanessa) ? "YES" : "YES") << endl;
	cout << "Can Mike and Alice travel together (should be NO)? "
		<< (mike.canTravelWith(alice) ? "YES" : "NO") << endl;
	cout << "----------------------------------------" << endl << endl;


	return 0;
}
