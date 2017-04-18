// OOP244 Milestone 5
// File Perishable.h
// Date 2017-04-17
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca


#ifndef ICT_PERISHABLE_H__
#define ICT_PERISHABLE_H__
#include <iostream>
#include "Date.h"   // Required to access the private member "Date m_expiry;".
#include "NonPerishable.h"

namespace ict {
// Perishable Items class
class Perishable : public NonPerishable {
private:
    Error m_err;
    Date m_expiry;

protected:
    // get Perishable signature/tag
    char signature() const;

public:
    // constructor
    Perishable();
    // save Perishable to file with expiry date
    virtual fstream& save(fstream&) const;
    // reads Perishable from istream
    virtual istream& read(istream&);
    // writes Perishable to file
    virtual ostream& write(ostream&, bool) const;
    // loads Perishable from file
    virtual fstream& load(fstream&);

};

istream& operator>>(istream&, Perishable&);
ostream& operator<<(ostream&, const Perishable&);

}
#endif
