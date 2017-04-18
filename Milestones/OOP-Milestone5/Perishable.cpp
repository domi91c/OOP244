// OOP244 Milestone 5
// File Perishable.cpp
// Date 2017-04-17
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca

// lib includes
#include <iostream>
#include "Perishable.h"

using namespace std;
namespace ict {

// constructor
Perishable::Perishable()
{
    m_expiry.dateOnly(true);
}

// get Perishable signature/tag
char Perishable::signature() const
{
    return 'P';
}

// save Perishable to file with expiry date
fstream& Perishable::save(fstream& file) const
{
    NonPerishable::save(file);
    file << ',' << m_expiry;
    return file;
}

// loads Perishable from file
fstream& Perishable::load(fstream& file)
{
    NonPerishable::load(file);
    return file;
}

// reads Perishable from istream
istream& Perishable::read(istream& is)
{
    cout << endl << "Perishable Item Entry:\n";
    NonPerishable::read(is);
    if (ok()) {
        m_expiry.dateOnly(true);
        cout << "Expiry date (YYYY/MM/DD): ";
        m_expiry.read(is);
        switch (m_expiry.errCode()) {
        case CIN_FAILED:error("Invalid Date Entry");
        case YEAR_ERROR:error("Invalid Year in Date Entry");
        case MON_ERROR:error("Invalid Month in Date Entry");
        case DAY_ERROR:error("Invalid Day in Date Entry");
        default:break;
        }
        if (NO_ERROR!=m_expiry.errCode())
            is.setstate(ios::failbit);
    }
    return is;
}

ostream& Perishable::write(ostream& os, bool linear) const
{
    NonPerishable::write(os, linear);
    if (!linear) {
        os << "Expiry date: ";
        m_expiry.write(os);
        os << endl;
    }
    return os;
}

istream& operator>>(istream& is, Perishable& perishable)
{
    perishable.read(is);
    return is;
}
ostream& operator<<(ostream& os, const Perishable& perishable)
{
    perishable.write(os, true);
    return os;
}
}
