// OOP244 Milestone 4
// File NonPerishable.h
// Date 2017-04-11
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca

#ifndef ICT_NONPERISHABLE_H__
#define ICT_NONPERISHABLE_H__

#include <iostream>
#include "Item.h"   // Required to use Item as a Base Class.
#include "Error.h"  // Required to access the "Error m_err;" member.
#include "PosIO.h"  // Required to access the pure virtual functions.

namespace ict {
class NonPerishable : public Item  // NonPerishable = Derived Class.  Item = Base Class.
{
private:

    Error m_err;                // Error Type named m_err.

protected:
    bool ok() const;
    void error(const char* message);

    // Returns the record tag N so it can be written in the NonPerishable file.
    virtual char signature() const { return 'N'; }

public:
    // istream,ostream and fstream for read, write and file methods.
    virtual std::fstream& save(std::fstream& file) const;
    virtual std::fstream& load(std::fstream& file);
    virtual std::ostream& write(std::ostream& os, bool linear) const;
    virtual std::istream& read(std::istream& is);

};
// Overload Operators for NonPerishable
std::istream& operator>>(std::istream&, NonPerishable&);
std::ostream& operator<<(std::ostream&, const NonPerishable&);

}
#endif