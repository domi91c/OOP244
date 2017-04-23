// OOP244 Milestone 5
// File NonPerishable.cpp
// Date 2017-04-17
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca

#include "NonPerishable.h"

using namespace std;
namespace ict {
// checks for error
bool NonPerishable::ok() const { return m_err.isClear(); }
// sets error message
void NonPerishable::error(const char* _message) { m_err = _message; }
// read item
istream& NonPerishable::read(istream& is)
{
    m_err.clear();
    char _sku[MAX_SKU_LEN];
    char _name[256];
    double _price;
    char _taxed;
    int _quantity;
    char _signature = signature();

    if (_signature=='N')
        cout << endl << "Item Entry:" << endl;

    cout << "Sku: ";
    is >> _sku;
    sku(_sku);
    cout << "Name:" << endl;
    is >> _name;
    name(_name);

    while (is.good()) {
        cout << "Price: ";
        if (is >> _price) {
            price(_price);
        }
        else {
            error("Invalid Price Entry");
            cout << m_err;
            is.ignore(10000);
            is.setstate(ios::failbit);
            break;
        }
        cout << "Taxed: ";
        if (is >> _taxed) {
            if (_taxed=='y' || _taxed=='Y') {
                taxed(true);
            }
            else if (_taxed=='n' || _taxed=='N') {
                taxed(false);
            }
            else {
                error("Invalid Taxed Entry, (y)es or (n)o");
                cout << m_err;
                is.ignore(10000);
                is.setstate(ios::failbit);
                break;
            }
        }
        else {
            error("Invalid Taxed Entry, (y)es or (n)o");
            cout << m_err;
            is.ignore(10000);
            is.setstate(ios::failbit);
            break;
        }
        cout << "Quantity: ";
        if (is >> _quantity) {
            quantity(_quantity);
        }
        else {
            error("Invalid Quantity Entry");
            cout << m_err;
            is.ignore(10000);
            is.setstate(ios::failbit);
        }
        break;
    }
    return is;

}
ostream& NonPerishable::write(ostream& os, bool linear) const
{
    if (ok()) {
        if (linear) {

            os.width(MAX_SKU_LEN);
            os << left << sku() << "|";
            os.width(20);
            os << name() << "|";
            os.setf(ios::fixed);
            os.setf(ios::right);
            os.width(7);
            os.precision(2);
            os << price() << "|";
            os.width(2);
            if (taxed())
                os << "T";
            else
                os << " ";
            os << signature() << "|";
            os.width(4);
            os << quantity() << "|";
            os.width(9);
            os.precision(2);
            os << (quantity()*cost()) << "|";
        }
        else {
            os << "Name:" << endl;
            os.setf(ios::left);
            os << name();
            os << endl;
            os << "Sku: " << sku() << endl;
            os << "Price: " << price() << endl;
            if (taxed())
                os << "Price after tax: " << price()+price()*TAX << endl;
            else
                os << "Price after tax: N/A" << endl;
            os << "Quantity: " << quantity() << endl;
            os << "Total Cost: " << fixed << (quantity()*cost()) << endl;
        }
    }
        // displays potential errors
    else {
        os << (const char*) (m_err);
    }
    return os;
}

// save NonPerishable to file in csv format
fstream& NonPerishable::save(fstream& file) const
{
    file << signature() << "," << sku() << "," << name() << "," << price() << ",";
    file << taxed() << "," << quantity();
    return file;
}

fstream& NonPerishable::load(fstream& file)
// load NonPerishable from file in csv format
{
    char _sku[MAX_SKU_LEN];
    char _name[256];
    double _price;
    bool _taxed;
    int _quantity;
    file.getline(_sku, MAX_SKU_LEN, ',');
    sku(_sku);
    file.getline(_name, 256, ',');
    name(_name);
    file >> _price;
    price(_price);
    file.ignore(1, ',');
    file >> _taxed;
    taxed(_taxed);
    file.ignore(1, ',');
    file >> _quantity;
    quantity(_quantity);
    return file;
}
// overloaded stdin and stdout operators for read and write
istream& operator>>(istream& is, NonPerishable& nonPerishable)
{
    nonPerishable.read(is);
    return is;
}
ostream& operator<<(ostream& os, const NonPerishable& nonPerishable)
{
    nonPerishable.write(os, true);
    return os;
}

}
