// OOP244 Milestone 5
// File NonPerishable.h
// Date 2017-04-17
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca

/*DONE*/



#ifndef ICT_NONPERISHABLE_H__
#define ICT_NONPERISHABLE_H__

#include <iostream>
#include "Item.h"
#include "Error.h"
#include "PosIO.h"

using namespace std;
namespace ict {

// NonPerishable Items class
class NonPerishable : public Item {
    Error m_err;
protected:
    // checks for error
    bool ok() const;
    // sets error message
    void error(const char* _message);
    // return signature
    virtual char signature() const { return 'N'; }
public:
    virtual fstream& save(fstream& file) const;
    virtual fstream& load(fstream& file);
    virtual ostream& write(ostream& os, bool linear) const;
    virtual istream& read(istream& is);
};
// overloaded stdin and stdout operators for read and write
istream& operator>>(istream&, NonPerishable&);
ostream& operator<<(ostream&, const NonPerishable&);

}
#endif