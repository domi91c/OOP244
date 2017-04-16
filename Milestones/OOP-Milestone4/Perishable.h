// OOP244 Milestone 4
// File Perishable.h
// Date 2017-04-11
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca



#ifndef ICT_PERISHABLE_H__
#define ICT_PERISHABLE_H__
#include <iostream>
#include "Date.h"
#include "NonPerishable.h"

namespace ict {
class Perishable: public NonPerishable    // Perishable = Derived Class. NonPerishable = Base Class.
{
private:

    Error m_err;      // This member is accessed by the NonPerisable.h which has the Error.h implemented.
    Date m_expiry;

protected:
    char signature() const;

public:
    // Constructor
    Perishable();

    // Pure Virtual Prototypes
    virtual std::fstream& save(std::fstream&) const;
    virtual std::ostream& write(std::ostream&, bool) const;
    virtual std::istream& read(std::istream&);
    virtual std::fstream& load(std::fstream&);

};
// Overload Operators for Perishable
std::istream& operator>>(std::istream&, Perishable&);
std::ostream& operator<<(std::ostream&, const Perishable&);

}
#endif