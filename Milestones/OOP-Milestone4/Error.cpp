// OOP244 Workshop Milestone 1
// File Error.cpp
// Date 2017-04-04
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca
#define _CRT_SECURE_NO_WARNINGS

#include "Error.h"
#include <cstring>

namespace ict {
Error::Error() { m_message = nullptr; }

Error::Error(const char* errorMessage)
{
    m_message = nullptr;
    message(errorMessage);
}

Error::~Error() { delete[] m_message; }

void Error::operator=(const char* errorMessage)
{
    clear();
    message(errorMessage);
}

void Error::clear()
{
    if (isClear()) {
        delete m_message;
    }

    else {
        delete[] m_message;
        m_message = nullptr;
    }
}

void Error::message(const char* msg)
{
    clear();
    char* temp = new char[strlen(msg)+1];

    strcpy(temp, msg);
    m_message = temp;
}

bool Error::isClear() const
{
    bool msg = false;

    if (m_message==nullptr) {
        msg = true;
    }
    return msg;
}

Error::operator const char*() const { return m_message; }

Error::operator bool() const { return m_message==nullptr; }

std::ostream& operator<<(std::ostream& os, const Error& error)
{
    if (!error.isClear()) {
        os << error.m_message;
    }

    return os;
}
}
