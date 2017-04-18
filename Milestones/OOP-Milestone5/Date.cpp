// OOP244 Milestone 5
// File Date.cpp
// Date 2017-04-17
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca

/*DONE*/

#include "Date.h"

#include <iomanip>
#include <iostream>
#include <ctime>
#include "POS.h"

using namespace std;
namespace ict {

// constructors
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
    m_year = year;
    m_mon = mon;
    m_day = day;
    m_hour = hour;
    m_min = min;
    m_readErrorCode = NO_ERROR;
}

// operator overloads
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

// get m_readErrorCode
int Date::errCode() const
{
    return m_readErrorCode;
}

// check error status
bool Date::bad() const
{
    bool err = false;
    if (m_readErrorCode!=NO_ERROR) {
        err = true;
    }
    return err;
}

// get m_dateOnly
bool Date::dateOnly() const
{
    return m_dateOnly;
}

// set m_dateOnly
void Date::dateOnly(bool value)
{
    m_dateOnly = value;
    if (value) {
        m_hour = 0;
        m_min = 0;
    }
}

// istream  and ostream read and write methods
istream& Date::read(istream& is)
{
    char slash, comma, colon;
    if (dateOnly()) {
        is >> m_year >> slash >> m_mon >> slash >> m_day;
    }
    else {
        is >> m_year >> slash >> m_mon >> slash >> m_day >> comma >> m_hour >> colon >> m_min;
    }

    if (is.fail()) {
        errCode(CIN_FAILED);
    }
    else if (MIN_YEAR>m_year || m_year>MAX_YEAR) {
        errCode(YEAR_ERROR);
    }
    else if (1>m_mon || m_mon>12) {
        errCode(MON_ERROR);
    }
    else if (m_day<1 || m_day>mdays()) {
        errCode(DAY_ERROR);
    }
    else if (0>m_hour || m_hour>23) {
        errCode(HOUR_ERROR);
    }
    else if (0>m_min || m_min>59) {
        errCode(MIN_ERROR);
    }
    else {
        errCode(NO_ERROR);
    }

    return is;
}

ostream& Date::write(ostream& os) const
{
    os << m_year << "/" << m_mon << "/" << m_day;
    if (!m_dateOnly) {
        os << ", " << m_hour << ":" << m_min;
    }
    return os;
}

istream& operator>>(istream& is, Date& date)
{
    date.read(is);
    return is;

}
ostream& operator<<(ostream& os, const Date& date)
{
    date.write(os);
    return os;
}
}

