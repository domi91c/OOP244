// OOP244 Workshop Milestone 1
// File Error.cpp
// Date 2017-04-04
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca


#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
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
    int error2 = (int) strlen(errorMessage);
    if (errorMessage) {
        delete[] m_message;
        m_message = new char[error2+1];
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
    bool msg = false;
    if (m_message==nullptr) {
        msg = true;
    }
    return msg;
}

void Error::message(const char* msg)
{
    int Emsg = (int) strlen(msg);
    if (msg) {
        clear();
        m_message = new char[Emsg+1];
        strcpy(m_message, msg);
    }
}

// cast overloads
Error::operator bool() const
{
    bool msg = false;
    if (isClear()) {
        msg = true;
    }
    return msg;
}

Error::operator const char*() const
{
    return m_message;
}

std::ostream& operator<<(std::ostream& ostream, Error& errorMessage)
{
    if (!errorMessage.isClear()) {
        ostream << (const char*) errorMessage;
    }
    return ostream;
}
}
