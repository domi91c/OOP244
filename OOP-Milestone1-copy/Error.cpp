// OOP244 Workshop Milestone 1
// File Error.cpp
// Date 2017-04-04
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca



#define _CRT_SECURE_NO_WARNINGS

#include "Error.h"

namespace ict {

// constructors
Error::Error()
{
    m_message = nullptr;
}

Error::Error(const char* errorMessage)
{
    m_message = nullptr;
    message(errorMessage);
}

// destructors
Error::~Error()
{
    delete[] m_message;
}

// operator= for c-style strings
void Error::operator=(const char* errorMessage)
{
    int errTwo = (int) strlen(errorMessage);
    if (errorMessage) {
        delete[] m_message;
        m_message = new char[errTwo+1];
        strcpy(m_message, errorMessage);
        clear();
        message(errorMessage);
    }
}

// methods
void Error::clear()
{
    delete[] m_message;
    m_message = nullptr;
}

bool Error::isClear() const
{
    bool Msg = false;
    if (m_message==nullptr) {
        Msg = true;
    }
    return Msg;
}

void Error::message(const char* value)
{
    int Emsg = (int) strlen(value);
    if (value) {
        clear();
        m_message = new char[Emsg+1];
        strcpy(m_message, value);
    }
}

// cast overloads
Error::operator bool() const
{
    bool ConMsg = false;
    if (isClear()) {
        ConMsg = true;
    }
    return ConMsg;
}

Error::operator const char*() const
{
    return m_message;
}

std::ostream& operator<<(std::ostream& ostr, Error& errorMessage)
{
    if (!errorMessage.isClear()) {
        ostr << (const char*) errorMessage;
    }
    return ostr;
}
}