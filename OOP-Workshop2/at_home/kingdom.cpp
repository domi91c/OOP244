// OOP244 Workshop 2 at_home
// File kingdom.cpp
// Date 2017-01-23
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca
//

// TODO: include the necessary headers
#include "kingdom.h"
#include <cstring>
#include <iostream>

using namespace std;
// TODO: the westeros namespace
namespace westeros {
// TODO:definition for display(...)
void display(Kingdom &kingdom) {
    cout << kingdom.m_name << ", population " << kingdom.m_population << endl;
}

void display(Kingdom kingdom[], int num) {
    int TOTAL_POPULATION = 0;
    cout << "------------------------------" << endl;
    cout << "Kingdoms of Westeros" << endl;
    cout << "------------------------------" << endl;
    for (int i = 0; i < num; i++) {
        cout << i + 1 << ". " << kingdom[i].m_name << ", population "
             << kingdom[i].m_population << endl;
        TOTAL_POPULATION += kingdom[i].m_population;
    }
    cout << "------------------------------" << endl;
    cout << "Total population of Westeros: " << TOTAL_POPULATION << endl;
    cout << "------------------------------" << endl;
}

void display(Kingdom kingdom[], int num, int MIN_POPULATION) {
    cout << "------------------------------" << endl;
    cout << "Kingdoms of Westeros with more than " << MIN_POPULATION
         << " people" << endl;
    cout << "------------------------------" << endl;
    for (int i = 0; i < num; i++) {
        if (kingdom[i].m_population >= MIN_POPULATION) {
            cout << kingdom[i].m_name << ", population "
                 << kingdom[i].m_population << endl;
        }
    }
    cout << "------------------------------" << endl;
}

void display(Kingdom kingdom[], int num, const char *KINGDOM_NAME) {
    bool kingdom_found = false;
    cout << "------------------------------" << endl;
    cout << "Searching for kingdom " << KINGDOM_NAME << " in Westeros" << endl;
    cout << "------------------------------" << endl;
    for (int i = 0; i < num; i++) {
        if (!strcmp(kingdom[i].m_name, KINGDOM_NAME)) {
            cout << kingdom[i].m_name << ", population "
                 << kingdom[i].m_population << endl;
            kingdom_found = true;
        }
    }
    if (!kingdom_found) {
        cout << KINGDOM_NAME << " is not part of Westeros." << endl;
    }
    cout << "------------------------------" << endl;
}
}
