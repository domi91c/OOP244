// OOP244 Milestone 5
// File PosApp.h
// Date 2017-04-17
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca

#ifndef ICT_POSAPP_H__
#define ICT_POSAPP_H__

#include<iostream>
#include"POS.h"
#include "NonPerishable.h"
#include "Perishable.h"
#include<fstream>
#include"Item.h"
#include<string.h>
#include<iomanip>

namespace ict {
// main class app is run from
class PosApp {
    char m_filename[128];
    char m_billfname[128];
    Item* m_items[MAX_NO_ITEMS];
    int m_noOfItems;
    int menu();
    void deallocateItems();
    void loadRecs();
    void saveRecs();
    int searchItems(const char* sku) const;
    void updateQty();
    void addItem(bool perishable);
    void listItems() const;
    void truncateBillFile();
    void showBill();
    void addToBill(Item& item);
    void POS();
public:
    // load records and display the menu
    void run();
    void testRun();
    // constructor
    PosApp(const char* filename, const char* billfname);
    // deleted single arg constructor
    PosApp(const PosApp& Pos) = delete;
    // deleted = operator
    PosApp& operator=(const PosApp& Pos) = delete;
    ~PosApp();
};

}

#endif