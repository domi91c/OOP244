// OOP244 Workshop Milestone 1
// File Error.h
// Date 2017-04-04
// Author Dominic Nunes
// Student Number 016-183-121 
// Email dcnunes@myseneca.ca
// compilation safegaurds

#ifndef ICT_Error_H_
#define ICT_Error_H_

#include <iostream>
namespace ict {
class Error {
    char* m_message;
public:
    // constructors
    Error();
    Error(const char* errorMessage);

    // destructor
    virtual ~Error();

    // deleted constructor and operator=
    Error(const Error& em) = delete;
    Error& operator=(const Error& em) = delete;

    // operator= for c-style strings
    void operator=(const char* errorMessage);

    // methods
    void clear();
    bool isClear() const;
    void message(const char* msg);

    // cast overloads
    operator const char*() const;
    operator bool() const;

    friend std::ostream& operator<<(std::ostream&, const Error& error);
};
// operator << overload prototype for cout
std::ostream& operator<<(std::ostream&, const Error& error);
}

#endif
