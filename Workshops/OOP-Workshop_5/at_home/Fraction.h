// OOP244 Workshop 5 at_home
// File Fraction.h
// Date 2017-02-21
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca

#ifndef SICT_Fraction_H__
#define SICT_Fraction_H__

#include <iostream>

using namespace std;

namespace sict {

class Fraction {
   private:
    int num;    // Numerator
    int denom;  // Denominator

    int gcd();  // returns the greatest common divisor of num and denom

    int max();  // returns the maximum of num and denom
    int min();  // returns the minimum of num and denom

   public:
    void reduce();  // simplifies a Fraction number by dividing the
    // numerator and denominator to their greatest common divisor

    Fraction();                  // default constructor
    Fraction(int n, int d = 1);  // construct n/d as a Fraction number

    void display() const;

    bool isEmpty() const;

    // member operator functions

    // TODO: write the prototype of member operator+= function HERE
    Fraction &operator+=(Fraction f2);

    // TODO: write the prototype of member operator+ function HERE
    Fraction operator+(Fraction f2);

    // TODO: write the prototype of member operator* function HERE
    Fraction operator*(Fraction f2);

    bool operator==(Fraction f2);
    bool operator!=(Fraction f2);
    operator double();
    operator int();
};
};
#endif
