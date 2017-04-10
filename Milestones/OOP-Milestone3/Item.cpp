// OOP244 Milestone 3
// File Item.cpp
// Date 2017-04-10
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca

#define _CRT_SECURE_NO_WARNINGS
// Lib includes
#include<iostream>
#include<cstring>

// inlcude Item and POS header files
#include "POS.h"
#include "PosIO.h"
#include "Item.h"
using namespace std;
namespace ict {


// Item class implementation

Item::Item()
{
    m_sku[0] = '\0';
    m_name = nullptr;
    m_price = 0;
    m_taxed = false;
    m_quantity = 0;
}

/* Four argument constructor*/
Item::Item(const char sku[], const char* name, double price, bool taxed)
{
    strcpy(m_sku, sku);
    m_name = new char[strlen(name)+1];
    strcpy(m_name, name);
    m_price = price;
    m_taxed = taxed;
    m_quantity = 0;
}

/* Copy Constructor*/
Item::Item(const Item& I)
{
    m_name = nullptr;
    strcpy(m_sku, I.m_sku);
    m_name = new char[strlen(I.m_name)+1];
    strcpy(m_name, I.m_name);
    m_price = I.m_price;
    m_taxed = I.m_taxed;
    m_quantity = I.m_quantity;
}
/* Copy assignment operator*/
Item& Item::operator=(const Item& I2)
{
    if (m_name!=nullptr && m_name[0]!='\0') {
        delete[] m_name;
    }
    strcpy(m_sku, I2.m_sku);
    m_name = new char[strlen(I2.m_name)+1];
    strcpy(m_name, I2.m_name);
    m_price = I2.m_price;
    m_taxed = I2.m_taxed;
    m_quantity = I2.m_quantity;
    return *this;
}

/* Virtual destructor*/
Item::~Item()
{
    delete[] m_name;
}

/* Void members (Modifiers)*/
void Item::sku(const char* d_sku)
{
    strcpy(m_sku, d_sku);
}

void Item::price(double d_price)
{
    m_price = d_price;
}

void Item::name(const char* d_name)
{
    if (m_name!=nullptr && m_name[0]!='\0') {
        delete[] m_name;
    }

    m_name = new char[strlen(d_name)+1];
    strcpy(m_name, d_name);
}

void Item::taxed(bool d_taxed)
{
    m_taxed = d_taxed;
}

void Item::quantity(int d_quantity)
{
    m_quantity = d_quantity;
}

/*	Query Functions*/
const char* Item::sku() const
{
    return m_sku;
}

double Item::price() const { return m_price; }

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
    if (m_taxed) {
        return (m_price*TAX)+m_price;
    }
    else {
        return m_price;
    }
}

/* IsEmpty function*/
bool Item::isEmpty()
{
    return ((m_sku[0] = '\0') && (m_name = nullptr) && (m_price = 0) && (m_taxed = 0) && (m_quantity = 0));
}

/* Assignment Operators*/
bool Item::operator==(const char* d_sku)
{
    return (strcmp(d_sku, m_sku)==0);
}

int Item::operator-=(int quantity)
{
    return Item::quantity()-quantity;
}

int Item::operator+=(int quantity)
{
    return Item::quantity()+quantity;
}

/* Operator+= for Item Class*/
double operator+=(double& d, const Item& I)
{
    return d+(I.price()*I.quantity());
}

std::ostream& Item::write(std::ostream& os, bool linear) const
{
    return os;
}

/* Operator << and >> overloads*/
std::istream& operator>>(std::istream& is, Item& r)
{
    r.read(is);
    return is;
}
std::ostream& operator<<(std::ostream& os, const Item& w)
{
    w.write(os, true);
    return os;
}

}