// OOP244 Milestone 3
// File Item.h
// Date 2017-04-10
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca



#ifndef ICT_ITEM_H__
#define ICT_ITEM_H__

#include "POS.h"
#include "PosIO.h"
namespace ict {
// class Item

class Item: public PosIO {

    // private members
    char m_sku[MAX_SKU_LEN+1];
    char* m_name;
    double m_price;
    bool m_taxed;
    int m_quantity;

public:

    // constructors
    Item();
    Item(const char[], const char*, double, bool taxed = true);
    Item(const Item&);
    Item& operator=(const Item&);
    ~Item();

    // modifiers
    void sku(const char*);
    void price(double);
    void name(const char*);
    void taxed(bool);
    void quantity(int);

    // Queries
    const char* sku() const;
    double price() const;
    char* name() const;
    bool taxed() const;
    int quantity() const;

    double cost() const;
    bool isEmpty();

    bool operator==(const char*);
    int operator+=(int);
    int operator-=(int);

    // Functions for input
    virtual std::ostream& write(std::ostream&, bool) const;
    virtual std::istream& read(std::istream&);

};

// end class Item
// operator +=
double operator+=(double& d, const Item& I);


// operator << and operator >>

std::istream& operator>>(std::istream&, Item&);
std::ostream& operator<<(std::ostream&, const Item&);
}

#endif