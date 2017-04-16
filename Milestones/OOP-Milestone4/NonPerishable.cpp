// OOP244 Milestone 4
// File NonPerishable.cpp
// Date 2017-04-11
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca

/* lib includes*/
#include "NonPerishable.h"
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using namespace std;
namespace ict {
bool NonPerishable::ok() const {
    if (this->m_err.isClear())  // Returns the m_err.isClear() true or else
        // returns false.
        return true;
    else
        return false;
}

void NonPerishable::error(const char* message) {
    m_err = message;  // Sets the m_err to message.
}

std::istream& NonPerishable::read(std::istream& is) {
    is.clear();
    this->m_err.clear();
    char s[MAX_SKU_LEN];
    char n[256];
    double p;
    char t;
    int q;
    char ch = signature();

    if (ch == 'N') cout << "Item Entry:" << endl;
    cout << "Sku: ";
    is >> s;

    if (is.fail() == false) {
        sku(s);
    }

    cout << "Name:" << endl;
    is >> n;
    name(n);
    cout << "Price: ";
    is >> p;
    if (!is.fail()) {
        price(p);
        cout << "Taxed: ";
        is >> t;

        if (!(t == 'Y' || t == 'y' || t == 'N' || t == 'n')) {
            m_err.message("Invalid Taxed Entry, (y)es or (n)o");
            is.setstate(ios::failbit);
        } else {
            if (t == 'y' || t == 'Y') {
                taxed(true);
            } else if (t == 'n' || t == 'N') {
                taxed(false);
            }
            cout << "Quantity: ";
            is >> q;

            if (is.fail()) {
                m_err.message("Invalid Quantity Entry");
                is.setstate(ios::failbit);
            } else {
                quantity(q);
            }
        }
    } else {
        m_err.message("Invalid Price Entry");
        is.setstate(ios::failbit);  // The read returns the is.
    }
    return is;
}

std::ostream& NonPerishable::write(std::ostream& os, bool linear) const {
    if (this->ok())  // Formatting a linear form using  public member functions
        // that support the ostream objects.
    {
        // Linear is true:
        if (linear) {
            os.width(MAX_SKU_LEN);
            os << std::left << this->sku() << "|";
            os.width(20);

            os << this->name() << "|";

            os.setf(ios::fixed);
            os.setf(ios::right);
            os.width(7);
            os.precision(2);
            os << this->price() << "|";
            os.width(2);
            if (this->taxed())
                os << "T";
            else
                os << " ";

            os << this->signature() << "|";
            os.width(4);
            os << this->quantity() << "|";

            os.width(9);
            os.precision(2);
            os << (this->quantity() * this->cost()) << "|";
        } else {
            os << "Name:" << endl;
            os.setf(ios::left);

            os << this->name();
            os << endl;
            os << "Sku: " << this->sku() << endl;

            os << "Price: " << this->price() << endl;

            if (this->taxed())
                os << "Price after tax: " << price() + price() * TAX << endl;
            else
                os << "Price after tax: N/A" << endl;
            os << "Quantity: " << this->quantity() << endl;
            os << "Total Cost: " << fixed << (this->quantity() * this->cost())
               << endl;
        }
    }

        // if the error occurs in the program, the error message is displayed.
    else {
        os << (const char*)(this->m_err);
    }

    return os;
}

std::fstream& NonPerishable::save(std::fstream& file) const
// The NonPerishable file saves the signature, sku, name, price, taxed and
// quantity.
{
    file << signature() << "," << sku() << "," << name() << "," << price()
         << ",";
    file << taxed() << "," << quantity();
    return file;
}

std::fstream& NonPerishable::load(std::fstream& file)
// The NonPerishable file loads the signature, sku, name, price, taxed and
// quantity
// to the ostream, by using temp variables to avoid commas and put setter
// members.
{
    char tempsku[MAX_SKU_LEN];
    char tempname[256];
    double tempprice;
    bool temptaxed;
    int tempquantity;
    file.getline(tempsku, MAX_SKU_LEN, ',');
    sku(tempsku);
    file.getline(tempname, 256, ',');
    name(tempname);
    file >> tempprice;
    price(tempprice);
    file.ignore(1, ',');
    file >> temptaxed;
    taxed(temptaxed);
    file.ignore(1, ',');
    file >> tempquantity;
    quantity(tempquantity);
    return file;
}

// Overload operator >> for read and operator << for write in the
// NonPerishable.cpp.
std::istream& operator>>(std::istream& is, NonPerishable& NPR) {
    NPR.read(is);
    return is;
}

std::ostream& operator<<(std::ostream& os, const NonPerishable& NPW) {
    NPW.write(os, true);
    return os;
}
}
