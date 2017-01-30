// OOP243 Workshop 2 at_home
// File w2_at_home.cpp
// Date 2017-01-26
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca
//

#include <iostream>
#include "kingdom.h"

using namespace std;
using namespace westeros;

int main(void) {
    int count = 0;  // the number of kingdoms in the array

    // TODO: declare the pKingdoms pointer here (don't forget to initialize it)
    Kingdom *pKingdoms;

    cout << "==========" << endl
         << "Input data" << endl
         << "==========" << endl
         << "Enter the number of kingdoms: ";
    cin >> count;
    cin.ignore();

    // TODO: allocate dynamic memory here for the pKingdoms pointer
    pKingdoms = new Kingdom[count];

    for (int i = 0; i < count; ++i) {
        // TODO: add code to accept user input for the kingdoms array

        cout << "Enter the name for kingdom #" << i + 1 << ": ";
        cin >> pKingdoms[i].m_name;
        cout << "Enter the number people living " << pKingdoms[i].m_name
             << ": ";
        cin >> pKingdoms[i].m_population;
    }
    cout << "==========" << endl << endl;

    // testing that "display(...)" works
    cout << "------------------------------" << endl
         << "The first kingdom of Westeros" << endl
         << "------------------------------" << endl;
    display(pKingdoms[0]);
    cout << "------------------------------" << endl << endl;

    // testing that the first overload of "display(...)" works
    display(pKingdoms, count);
    cout << endl;

    // testing that the second overload of "display(...)" works
    display(pKingdoms, count, 345678);
    cout << endl;

    // testing that the third overload of "display(...)" works
    display(pKingdoms, count, "Mordor");
    cout << endl;

    display(pKingdoms, count, "The_Vale");
    cout << endl;

    // TODO: deallocate the dynamic memory here
    delete[] pKingdoms;

    return 0;
}
