// OOP244 Milestone 4
// File Perishable.cpp
// Date 2017-04-11
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca


// lib includes
#include "Perishable.h"
#include <iostream>

using namespace std;
namespace ict {
// Constructor
Perishable::Perishable()
{
    m_expiry.dateOnly(true);  // Returns the m_expiry.dateOnly true in the dateonly mode.
}

char Perishable::signature() const
{
    return 'P';  // Returns the record tag P so it can be written in the
    // Perishable file.
}

std::fstream& Perishable::save(std::fstream& file) const
{
    NonPerishable::save(file);  // Calls the NonPerisable::save, add the ',' and
    // m_expiry; to the file then returns the
    // file.
    file << ',' << m_expiry;
    return file;
}

std::fstream& Perishable::load(std::fstream& file)
{
    NonPerishable::load(file);  // Calls the NonPerisable::load and returns the file.
    return file;
}

std::istream& Perishable::read(std::istream& is)
{
    cout << "Perishable Item Entry:\n";
    NonPerishable::read(is);
    if (ok()) {
        m_expiry.dateOnly(true);
        cout << "Expiry date (YYYY/MM/DD): ";
        m_expiry.read(is);

        // check the error code

        // If each specific error is compared to current m_expiry.errCode()),
        // the current specicfic error will assign to a specific invalid error
        // message.
        if (CIN_FAILED==m_expiry.errCode())
            error("Invalid Date Entry");
        else if (YEAR_ERROR==m_expiry.errCode())
            error("Invalid Year in Date Entry");
        else if (MON_ERROR==m_expiry.errCode())
            error("Invalid Month in Date Entry");
        else if (DAY_ERROR==m_expiry.errCode())
            error("Invalid Day in Date Entry");

        if (NO_ERROR!=m_expiry.errCode())
            is.setstate(ios::failbit);  // failed
    }
    return is;
}

std::ostream& Perishable::write(std::ostream& os, bool linear) const
{
    NonPerishable::write(os, linear);
    // inputs Expiry Date to ostream if linear is false
    if (!linear) {
        os << "Expiry date: ";
        m_expiry.write(os);
        os << endl;
    }
    return os;
}

// Overload operator >> for read  and operator << for write in the
// Perishable.cpp.
std::istream& operator>>(std::istream& is, Perishable& p)
{
    p.read(is);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Perishable& p)
{
    p.write(os, true);
    return os;
}
}

