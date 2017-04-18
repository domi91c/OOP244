// OOP244 Milestone 5
// File PosApp.cpp
// Date 2017-04-17
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca

#include "PosApp.h"

using namespace std;
namespace ict {

// constructor
PosApp::PosApp(const char* filename, const char* billfname)
{
    strcpy(m_filename, filename);
    strcpy(m_billfname, billfname);
    m_items[0] = (Item*) "\0";
    m_noOfItems = 0;
}

// destructor
PosApp::~PosApp()
{
    deallocateItems();
}

// load records and display the menu
void PosApp::run()
{
    loadRecs();
    int select;
    do {
        select = menu();
        if (select>0) {
            switch (select) {
            case 1: listItems();
                break;
            case 2: addItem(true);
                break;
            case 3: addItem(false);
                break;
            case 4: updateQty();
                break;
            case 5: {
                cout << endl << "Please enter the SKU: ";
                char sku[MAX_SKU_LEN];
                cin >> sku;
                int i = searchItems(sku);
                if (i!=-1) {
                    cout << "v-----------------------------------v" << endl;
                    m_items[i-1]->write(cout, false);
                    cout << "^-----------------------------------^" << endl;
                }
                else {
                    cout << "Not found!";
                }
                cout << endl;
                break;
            }
            case 6: POS();
                break;
            default:break;
            }
        }
        if (select==0)
            cout << endl << "Goodbye!" << endl << endl;
        else if (select==-1 || select>5)
            cout << endl << "===Invalid Selection, try again===" << endl << endl;
    }
    while (select!=0);
}

// display the main menu
int PosApp::menu()
{
    int select;
    cout << "The Sene-Store" << endl;
    cout << "1 - List items" << endl;
    cout << "2 - Add Perishable item " << endl;
    cout << "3 - Add Non - Perishable item" << endl;
    cout << "4 - Update item quantity" << endl;
    cout << "5 - Show Item" << endl;
    cout << "6 - POS" << endl;
    cout << "0 - exit program" << endl;
    cout << "> ";
    cin.clear();
    cin >> select;
    if (select<0 || select>6 || cin.fail()) {
        select = -1;
    }
    return select;
}

// clear m_items array
void PosApp::deallocateItems()
{
    for (int i = 0; i<m_noOfItems; i++) {
        delete[] m_items[i];
    }
}

// load all items
void PosApp::loadRecs()
{
    deallocateItems();
    fstream f;
    f.open(m_filename, fstream::in);
    if (f.fail()) {
        f.clear();
        f.close();
        f.open(m_filename, fstream::out);
        return;
    }
    while (!f.eof()) {
        char c;
        f >> c;
        if (c=='P') {
            m_items[m_noOfItems] = new Perishable();
            f >> c;
            m_items[m_noOfItems]->load(f);
            m_noOfItems++;
        }
        if (c=='N') {
            m_items[m_noOfItems] = new NonPerishable();
            f >> c;
            m_items[m_noOfItems]->load(f);
            m_noOfItems++;
        }
    }
    f.close();
}

// overwrites the data in the data file
void PosApp::saveRecs()
{
    fstream file(m_filename, ios::out);
    if (file.is_open()) {
        for (int i = 0; i<m_noOfItems; i++) {
            // only if their quantity is more than zero
            if (m_items[i]->quantity()>0) {
                m_items[i]->save(file);
                file << '\n';
            }
        }
        file.close();
    }
    loadRecs();
}

// find item by sku
int PosApp::searchItems(const char* sku) const
{
    int index = -1;
    for (int i = 0; i<m_noOfItems; i++) {
        if (*(m_items[i])==sku) {
            index = i+1;
            break;
        }
    }
    return index;
}

// update quantity of item by SKU
void PosApp::updateQty()
{
    char sku[MAX_SKU_LEN];
    int quant;
    cout << endl << "Please enter the SKU: ";
    cin >> sku;
    int index = searchItems(sku);
    if (index!=-1) {
        m_items[index-1]->write(cout, false);
        cout << endl << "Please enter the number of purchased items: ";
        cin >> quant;
        *(m_items[index-1]) += quant;
        saveRecs();
        cout << "Updated!" << endl << endl;
    }
    else {
        cout << "Not found!" << endl << endl;
    }
}

// add item and save in data file
void PosApp::addItem(bool perishable)
{
    if (perishable) {
        m_items[m_noOfItems] = new Perishable();
    }
    else {
        m_items[m_noOfItems] = new NonPerishable();
    }
    m_items[m_noOfItems]->read(cin);
    if (!cin.fail()) {
        m_noOfItems++;
    }
    cout << "Item Added.\n" << endl;
}

// print inventory
void PosApp::listItems() const
{
    double asset = 0;
    cout << endl << "Row  | SKU    | Item Name          | Price |TX |Qty |   Total |" << endl;
    cout << "-----|--------|--------------------|-------|---|----|---------|" << endl;
    for (int i = 0; i<m_noOfItems; i++) {
        cout << setw(5) << right << i+1 << "| ";
        m_items[i]->write(cout, true);
        cout << "\n";
        if (!m_items[i]->taxed()) {
            asset += (m_items[i]->quantity())*(m_items[i]->price());
        }
        else {
            asset += (m_items[i]->quantity())*(m_items[i]->price())*(1+TAX);
        }
    }
    cout << "-----^--------^--------------------^-------^---^----^---------^" << endl;
    cout << "                                Total Asset: $ |" << setw(14) << right << setprecision(2) << fixed << asset
         << "|" << endl;
    cout << "-----------------------------------------------^--------------^" << endl << endl;
}

void PosApp::truncateBillFile()
{
    fstream f;
    f.open(m_billfname, fstream::out | fstream::trunc);
    f.close();
}

// display contents of bill file and truncates
void PosApp::showBill()
{
    double asset = 0;
    cout << "v-------------------------------------------------------------v" << endl;
    cout << "| " << "2017/04/02, 12:42" << "                                           |" << endl;
    cout << "Row  | SKU    | Item Name          | Price |TX |Qty |   Total |" << endl;
    cout << "-----|--------|--------------------|-------|---|----|---------|" << endl;

    fstream f;
    f.open(m_billfname, fstream::in);
    while (!f.eof()) {
        Item* item;
        int j = 1;
        char tag;
        f >> tag;
        if (tag=='P') {
            item = new Perishable();
            f >> tag;
            item->load(f);
            cout << setw(5) << right << j++ << "| ";
            item->write(cout, true);
            cout << endl;
            if (!item->taxed()) {
                asset += (item->quantity())*(item->price());
            }
            else {
                asset += (item->quantity())*(item->price())*(1+TAX);
            }
            delete item;
        }
        if (tag=='N') {
            item = new NonPerishable();
            f >> tag;
            item->load(f);
            cout << setw(5) << right << j++ << "| ";
            item->write(cout, true);
            cout << endl;
            if (!item->taxed()) {
                asset += (item->quantity())*(item->price());
            }
            else {
                asset += (item->quantity())*(item->price())*(1+TAX);
            }
            delete item;
        }
    }
    cout << "-----^--------^--------------------^-------^---^----^---------^" << endl;
    cout << "                                Total Asset: $ |" << setw(14) << right << setprecision(2) << fixed << asset
         << "|" << endl;
    cout << "-----------------------------------------------^--------------^" << endl << endl;
}

// add an item to the bill file
void PosApp::addToBill(Item& I)
{
    fstream wrfile(m_billfname, ios::out | ios::app);
    // if failure
    if (wrfile.is_open()) {
        wrfile << "P," << I.sku() << "," << I.name() << "," << I.price() << "," << I.taxed() << "," << I.quantity()
               << '\n';
    }
    wrfile.close();
}

// sku input loop
void PosApp::POS()
{
    char sku[MAX_SKU_LEN] = {'\0'};
    cout << endl;
    do {
        cout << "Sku: ";
        //cin >> sku;
        cin.ignore();
        cin.get(sku, MAX_SKU_LEN+1);
        int idx = searchItems(sku);
        if (idx>0) {
            cout << "v------------------->" << endl;
            cout << "| " << m_items[idx-1]->name() << endl;
            cout << "^------------------->" << endl;
            addToBill(*(m_items[idx-1]));
        }
            // when a input value exists, print a message
        else if (strlen(sku)>0) {
            cout << "Not found!" << endl;
        }
    }
    while (strlen(sku)>0);
    showBill();
    truncateBillFile();
}
}

