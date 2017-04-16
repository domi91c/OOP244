// OOP244 Workshop Milestone 1
// File Error.h
// Date 2017-04-04
// Author Dominic Nunes
// Student Number 016-183-121 
// Email dcnunes@myseneca.ca



// compilation safegaurds
#ifndef ICT_ERROR_H__
#define ICT_ERROR_H__

#include <iostream>
namespace ict {
class Error {

    char* m_message; // Encapsulates dynamic C-style string memory
public:

    // constructors
    Error();
    Error(const char* errorMessage);

    // destructor
    virtual ~Error();

    // deleted constructor and operator=
    Error& operator=(const Error& em) = delete;
    Error(const Error& em) = delete;

    // operator= for c-style strings
    void operator=(const char* errorMessage);

    // methods
    void clear();
    bool isClear() const;
    void message(const char* value);

    // cast overloads
    operator bool() const;
    operator const char*() const;

};
// operator << overload prototype for cout
std::ostream& operator<<(std::ostream&, Error&);
}

#endif


