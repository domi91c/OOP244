// OOP244 Milestone 3
// File posIO.h
// Date 2017-04-10
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca

#ifndef ICT_POSIO_H__
#define ICT_POSIO_H__
#include <fstream>
#include <iostream>

namespace ict
{
class PosIO
{
public:
    virtual std::fstream &save(std::fstream &file) const
    { return file; }
    virtual std::fstream &load(std::fstream &file)
    { return file; }
    virtual std::ostream &write(std::ostream &os, bool linear) const
    { return os; }
    virtual std::istream &read(std::istream &is)
    { return is; }
};

}
#endif
