// OOP244 Milestone 5
// File Error.h
// Date 2017-04-17
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca

// compilation safegaurds
#ifndef ICT_ERROR_H__
#define ICT_ERROR_H__

#include <iostream>

using namespace std;

namespace ict {
// error handling class
class Error {
    char* m_message;
public:

    // constructor
    Error();
    // 1 arg constructor
    Error(const char* errorMessage);
    // destructor
//    ~Error();
    virtual ~Error();
    // deleted constructor and copy constructor
    Error& operator=(const Error& em) = delete;
    Error(const Error& em) = delete;
    // = operator
    void operator=(const char* errorMessage);
    // clear m_message
    void clear();
    // check if m_message is clear
    bool isClear() const;
    // set m_message
    void message(const char* m);
    // casting overloads
    operator bool() const;
    operator const char*() const;
// << operator overload

};

ostream& operator<<(ostream& os, const Error& error);
}

#endif

