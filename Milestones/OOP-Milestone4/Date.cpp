// OOP244 Workshop Milestone 1
// File Date.cpp
// Date 2017-04-04
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca



#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
#include "Date.h"
#include "POS.h"

using namespace std;

namespace ict {

// private methods
void Date::set()
{
    time_t t = time(NULL);
    tm lt = *localtime(&t);
    m_day = lt.tm_mday;
    m_mon = lt.tm_mon+1;
    m_year = lt.tm_year+1900;
    if (dateOnly()) {
        m_hour = m_min = 0;
    }
    else {
        m_hour = lt.tm_hour;
        m_min = lt.tm_min;
    }
}

int Date::value() const
{
    return m_year*535680+m_mon*44640+m_day*1440+m_hour*60+m_min;
}

int Date::mdays() const
{
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1};
    int mon = m_mon>=1 && m_mon<=12 ? m_mon : 13;
    mon--;
    return days[mon]+int((mon==1)*((m_year%4==0) && (m_year%100!=0)) || (m_year%400==0));
}

void Date::errCode(int errorCode)
{
    m_readErrorCode = errorCode;
}

void Date::set(int year, int mon, int day, int hour, int min)
{
    m_readErrorCode = NO_ERROR;
}

Date::Date()
{

    m_dateOnly = false;
    set();

}

Date::Date(int year, int mon, int day)
{

    m_dateOnly = true;

    m_year = year;
    m_mon = mon;
    m_day = day;
    m_hour = 0;
    m_min = 0;

    m_readErrorCode = NO_ERROR;

}

Date::Date(int year, int mon, int day, int hour, int min)
{
    m_dateOnly = false;

    m_year = year;
    m_mon = mon;
    m_day = day;
    m_hour = hour;
    m_min = min;
    m_readErrorCode = NO_ERROR;
}

bool Date::operator==(const Date& D) const
{
    return value()==D.value();
}
bool Date::operator!=(const Date& D) const
{
    return value()!=D.value();
}
bool Date::operator<(const Date& D) const
{
    return value()<D.value();
}
bool Date::operator>(const Date& D) const
{
    return value()>D.value();
}
bool Date::operator<=(const Date& D) const
{
    return value()<=D.value();
}
bool Date::operator>=(const Date& D) const
{
    return value()>=D.value();
}

int Date::errCode() const
{
    return m_readErrorCode;
}

bool Date::bad() const
{
    bool err = false;
    if (m_readErrorCode!=NO_ERROR) {
        err = true;
    }
    return err;
}

bool Date::dateOnly() const
{
    return m_dateOnly;
}

void Date::dateOnly(bool value)
{
    m_dateOnly = value;
    if (value) {
        m_hour = 0;
        m_min = 0;
    }
}

// istream  and ostream read and write methods
std::istream& Date::read(std::istream& is)
{
    char slash, comma, colon;

    if (dateOnly()) {
        is >> m_year >> slash >> m_mon >> slash >> m_day;
    }
    else {
        is >> m_year >> slash >> m_mon >> slash >> m_day >> comma >> m_hour >> colon >> m_min;
    }
    // check error type and set code
    // check istream failed and set error code
    if (is.fail()) {
        errCode(CIN_FAILED);
    }

        // if between MIN_YEAR and MAX_YEAR, correct;otherwise error
    else if (MIN_YEAR>m_year || m_year>MAX_YEAR) {
        errCode(YEAR_ERROR);
    }

        // if between 1 to 12, correct;otherwise error
    else if (1>m_mon || m_mon>12) {
        errCode(MON_ERROR);
    }

        // if greater than the end day of month, error
    else if (m_day>mdays()) {
        errCode(DAY_ERROR);
    }

        // if between 0 and 23, correct;otherwise error
    else if (0>m_hour || m_hour>23) {
        errCode(HOUR_ERROR);
    }

        // if between 0 and 23, correct;otherwise error
    else if (0>m_min || m_min>59) {
        errCode(MIN_ERROR);
    }

    return is;
}

std::ostream& Date::write(std::ostream& ostr) const
{
    ostr << m_year << "/";

    if (m_mon<=10) {
        ostr << "0" << m_mon;
    }
    else {
        ostr << m_mon;
    }

    ostr << "/";

    if (m_day<=10) {
        ostr << "0" << m_day;
    }
    else {
        ostr << m_day;
    }
    if (!(dateOnly()))

        ostr << ", " << m_hour << ":" << m_min;
    return ostr;
}

std::istream& operator>>(std::istream& is, Date& D)
{
    D.read(is);
    return is;
}

std::ostream& operator<<(std::ostream& ostr, const Date& D)
{
    D.write(ostr);
    return ostr;
}
}

  
