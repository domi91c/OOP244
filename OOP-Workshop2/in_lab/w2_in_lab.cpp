// OOP244 Workshop 2
// File w2_in_lab.cpp
// Date 2017-01-23
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca
//

#include <string>

#include <iostream>
#include "kingdom.h"

using namespace std;
using namespace westeros;

int main(void) {
    int count = 0;  // the number of kingdoms in the array

    // TODO: declare the kingdoms pointer here (don't forget to initialize it)
    Kingdom *pKingdoms = nullptr;

    cout << "==========" << endl
         << "Input data" << endl
         << "==========" << endl
         << "Enter the number of kingdoms: ";
    cin >> count;
    cin.ignore();

    // TODO: allocate dynamic memory here for the kingdoms pointer
    pKingdoms = new Kingdom[count];

    for (int i = 0; i < count; ++i) {
        // TODO: add code to accept user input for the kingdoms array

        cout << "Enter the name for kingdom #" << i + 1 << ":";
        cin >> pKingdoms[i].m_name;
        cout << "Enter the number people living " << pKingdoms[i].m_name << ": ";
        cin >> pKingdoms[i].m_population;
    }
    cout << "==========" << endl << endl;

    // testing that "display(...)" works
    cout << "------------------------------" << endl
         << "The first kingdom of Westeros" << endl
         << "------------------------------" << endl;
    display(pKingdoms[0]);
    cout << "------------------------------" << endl << endl;

    // TODO: deallocate the dynamic memory here
    delete[] pKingdoms;

    return 0;
}
