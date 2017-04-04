// OOP244 Workshop 5: operators overloading
// File: w5_in_lab.cpp
// Version: 1.0
// Date: 2016/01/22
// Author: Heidar Davoudi
// Description:
// This file tests in-lab section of your workshop
/////////////////////////////////////////////

#include <iostream>
#include "Fraction.h"

using namespace sict;
using namespace std;


int main(){

    cout << "------------------------------" << endl;

    cout << "Fraction Class Operators Test:" << endl;
    cout << "------------------------------" << endl;
    
    Fraction A;
    cout << "Fraction A; // ";
    cout << "A = ";
    A.display();
    cout << endl;

    Fraction B(1, 3);
    cout << "Fraction B(1, 3); // ";
    cout << "B = ";
    B.display();
    cout << endl;

    
    Fraction C(-5, 15);
    cout << "Fraction C(-5, 15); //";
    cout << " C = " ;
    C.display();
    cout << endl;

    Fraction D(2, 4);
    cout << "Fraction D(2, 4); //";
    cout << " D = ";
    D.display();
    cout << endl;

    Fraction E(8, 4);
    cout << "Fraction E(8, 2); //";
    cout << " E = " ;
    E.display();
    cout << endl;

    cout << endl;

    cout << "(B*Rational(6) == E) equals ";
    cout << (B*Fraction(6) == E);
    cout << endl;

    cout << "(A == C) equals ";
    cout << (A == C);
    cout << endl;

    cout << "(double) B equals ";
    cout.precision(3);
    cout << (double) B;
    cout << endl;


    cout << "(int) B equals ";
    cout << (int) B;
    cout << endl;

    cout << "S := ";

    Fraction s = 0;
    for(Fraction r = Fraction(1,2) ; r != Fraction(3,1);r +=Fraction(1,4)){
        r.display();
        cout  << ", " ;
        s += r;
    }

    cout << endl << "The sum of elements in S equals " ;
    s.display();
    cout << endl ;
   
    return 0;
}
