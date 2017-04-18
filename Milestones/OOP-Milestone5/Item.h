// OOP244 Milestone 5
// File Item.h
// Date 2017-04-17
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca

/*DONE*/

#ifndef ICT_ITEM_H__
#define ICT_ITEM_H__
#include "POS.h"
#include "PosIO.h"

namespace ict {
class Item : public PosIO {

    // private members
    char m_sku[MAX_SKU_LEN+1];
    char* m_name;
    double m_price;
    bool m_taxed;
    int m_quantity;

public:

    // constructor
    Item();
    // 4 arg constructor
    Item(const char[], const char*, double, bool taxed = true);
    // copy constructor
    Item(const Item&);
    // copy assignment operator
    Item& operator=(const Item&);
    // destructor
    virtual ~Item();

    // setters
    void sku(const char*);
    void price(double);
    void name(const char*);
    void taxed(bool);
    void quantity(int);

    // getters
    const char* sku() const;
    double price() const;
    char* name() const;
    bool taxed() const;
    int quantity() const;
    double cost() const;

    // safe and empty check
    bool isEmpty();

    // assignment operator overloads
    bool operator==(const char*);
    int operator+=(int);
    int operator-=(int);
};

// operator +=
double operator+=(double& number, const Item& item);

// operator << and operator >>
istream& operator>>(istream&, Item&);
ostream& operator<<(ostream&, const Item&);
}

#endif