// OOP244 Workshop Milestone 1
// File PosIO.h
// Date 2017-04-04
// Author Dominic Nunes
// Student Number 016-183-121 
// Email dcnunes@myseneca.ca

#ifndef ICT_POSIO_H__
#define ICT_POSIO_H__
// includes go here
#include <fstream>
#include <iostream>

#define TAX 0.13
#define MAX_SKU_LEN 7
#define MIN_YEAR 2000
#define MAX_YEAR 2030
#define MAX_NO_ITEMS 2000

//ict namespace
namespace ict {
class PosIO {
public:
    // pure virutal methods go here
    std::fstream& save(std::fstream& file) const { return file; }
    std::fstream& load(std::fstream& file) { return file; }
    std::ostream& write(std::ostream& os, bool linear) const { return os; }
    std::istream& read(std::istream& is) { return is; }
};

}
#endif