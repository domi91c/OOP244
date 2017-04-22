// OOP244 Milestone 5
// File Item.cpp
// Date 2017-04-17
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca

/*DONE*/

// Lib includes
#include<iostream>
#include<cstring>
#include "POS.h"
#include "PosIO.h"
#include "Item.h"

using namespace std;
namespace ict {

// constructor
Item::Item()
{
    m_sku[0] = '\0';
    m_name = nullptr;
    m_price = 0;
    m_taxed = false;
    m_quantity = 0;
}

// 4 arg constructor
Item::Item(const char sku[], const char* name, double price, bool taxed)
{
    strcpy(m_sku, sku);
    m_name = new char[strlen(name)+1];
    strcpy(m_name, name);
    m_price = price;
    m_taxed = taxed;
    m_quantity = 0;
}

// copy constructor
Item::Item(const Item& item)
{
    strcpy(m_sku, item.m_sku);
    m_price = item.m_price;
    m_quantity = item.m_quantity;
    m_taxed = item.m_taxed;

    if (item.m_name==nullptr) {
        m_name = nullptr;
    }
    else {
        m_name = new char[strlen(item.m_name)+1];
        strncpy(m_name, item.m_name, strlen(item.m_name)+1);

    }

}
// assignment operator
Item& Item::operator=(const Item& item)
{
    if (!isEmpty()) {
        name(item.m_name);
        m_quantity = item.m_quantity;
    }
    return *this;
}

// destructor
Item::~Item()
{
    delete[] m_name;
}

// setters
void Item::sku(const char* s)
{
    strcpy(m_sku, s);
}
void Item::price(double p)
{
    m_price = p;
}
void Item::name(const char* n)
{
//    if (m_name!=nullptr && m_name[0]!='\0') {
//        delete[] m_name;
//    }
    m_name = new char[strlen(n)+1];
    strcpy(m_name, n);
}
void Item::taxed(bool t)
{
    m_taxed = t;
}
void Item::quantity(int q)
{
    m_quantity = q;
}

// getters
const char* Item::sku() const
{
    return m_sku;
}
double Item::price() const
{
    return m_price;
}
char* Item::name() const
{
    return m_name;
}
bool Item::taxed() const
{
    return m_taxed;
}
int Item::quantity() const
{
    return m_quantity;
}
double Item::cost() const
{
    return m_taxed ? (m_price*TAX)+m_price : m_price;
}

// safe and empty check
bool Item::isEmpty()
{
    return m_sku[0]=='\0' && m_name==nullptr && m_price==0 && m_taxed==0 && m_quantity==0;
}

// assignment operator overloads
bool Item::operator==(const char* _sku)
{
    return strcmp(_sku, m_sku)==0;
}
int Item::operator-=(int _quantity)
{
    return quantity()-_quantity;
}
int Item::operator+=(int _quantity)
{
    return quantity()+_quantity;
}

// += operator (number, Item)
double operator+=(double& number, const Item& item)
{
    return number+(item.price()*item.quantity());
}

// output operator (read)
istream& operator>>(istream& is, Item& r)
{
    r.read(is);
    return is;
}

// input operator (write)
ostream& operator<<(ostream& os, const Item& w)
{
    w.write(os, true);
    return os;
}
}