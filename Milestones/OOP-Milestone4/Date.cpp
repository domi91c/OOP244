// OOP244 Workshop Milestone 1
// File Date.cpp
// Date 2017-04-04
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca

#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;
#include "Date.h"
#include "POS.h"

namespace ict {
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

void Date::set(int year, int month, int day, int hour, int min)
{
    m_year = year;
    m_mon = month;
    m_day = day;
    m_hour = hour;
    m_min = min;
    m_readErrorCode = NO_ERROR;
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
    return days[mon]+
            int((mon==1)*((m_year%4==0) && (m_year%100!=0)) ||
                    (m_year%400==0));
}

void Date::errCode(int errorCode)
{
    switch (errorCode) {
    case 0:m_readErrorCode = NO_ERROR;
        break;

    case 1:m_readErrorCode = CIN_FAILED;
        break;

    case 2:m_readErrorCode = YEAR_ERROR;
        break;

    case 3:m_readErrorCode = MON_ERROR;
        break;

    case 4:m_readErrorCode = DAY_ERROR;
        break;

    case 5:m_readErrorCode = HOUR_ERROR;
        break;

    case 6:m_readErrorCode = MIN_ERROR;
        break;
    }
}

Date::Date()
{
    dateOnly(false);
    set();
}

Date::Date(int year, int month, int day)
{
    dateOnly(true);
    set(year, month, day, 0, 0);
}

Date::Date(int year, int month, int day, int hour, int min)
{
    dateOnly(false);
    set(year, month, day, hour, min);
}

bool Date::operator==(const Date& D) const
{
    return (this->value()==D.value());
}

bool Date::operator!=(const Date& D) const
{
    return (this->value()!=D.value());
}

bool Date::operator<(const Date& D) const
{
    return (this->value()<D.value());
}

bool Date::operator>(const Date& D) const
{
    return (this->value()>D.value());
}

bool Date::operator<=(const Date& D) const
{
    return (this->value()<=D.value());
}

bool Date::operator>=(const Date& D) const
{
    return (this->value()>=D.value());
}

int Date::errCode() const { return m_readErrorCode; }

bool Date::bad() const { return (m_readErrorCode!=0); }

bool Date::dateOnly() const { return m_dateOnly; }

void Date::dateOnly(bool value)
{
    m_dateOnly = value;

    if (value==true) {
        m_hour = 0;
        m_min = 0;
    }
}

std::istream& Date::read(std::istream& is)
{
    int year = 0;
    int mon = 0;
    int day = 0;
    int hour = 0;
    int min = 0;

    const char forslash = '/';
    const char comma = ',';
    const char colon = ':';

    errCode(NO_ERROR);

    is >> year;

    if (is.fail()) {
        errCode(CIN_FAILED);
        return is;
    }

    if (is.get()!=forslash) {
        errCode(CIN_FAILED);
        return is;
    }

    is >> mon;

    if (is.fail()) {
        errCode(CIN_FAILED);
        return is;
    }

    if (is.get()!=forslash) {
        errCode(CIN_FAILED);
        return is;
    }

    if (dateOnly()) {
        is >> day;
        if (is.fail()) {
            errCode(CIN_FAILED);
            return is;
        }

        if (NO_ERROR==errCode()) {
            set(year, mon, 0, 0, 0);
            if (year<2000 || year>2300) {
                errCode(YEAR_ERROR);
            }

            else if (mon<1 || mon>12) {
                errCode(MON_ERROR);
            }

            else if (day<1 || day>mdays()) {
                errCode(DAY_ERROR);
            }
        }
        m_day = day;
        return is;
    }

    else {
        is >> day;
        if (is.fail()) {
            errCode(CIN_FAILED);
            return is;
        }

        if (is.get()!=comma) {
            errCode(CIN_FAILED);
            return is;
        }

        is >> hour;
        if (is.fail()) {
            errCode(CIN_FAILED);
            return is;
        }

        if (is.get()!=colon) {
            errCode(CIN_FAILED);
            return is;
        }

        is >> min;
        if (is.fail()) {
            errCode(CIN_FAILED);
            return is;
        }

        if (NO_ERROR==errCode()) {
            set(year, mon, 0, 0, 0);
            if (year<2000 || year>2300) {
                errCode(YEAR_ERROR);
            }

            else if (mon<1 || mon>12) {
                errCode(MON_ERROR);
            }

            else if (day<1 || day>mdays()) {
                errCode(DAY_ERROR);
            }

            else if (hour<0 || hour>23) {
                errCode(HOUR_ERROR);
            }

            else if (min<0 || min>59) {
                errCode(MIN_ERROR);
            }
        }

        m_day = day;
        m_hour = hour;
        m_min = min;
        return is;
    }
    return is;
}

std::ostream& Date::write(std::ostream& ostr) const
{
    if (dateOnly()) {
        if (m_mon<10) {
            if (m_day<10) {
                ostr << m_year << "/0" << m_mon << "/0" << m_day;
            }

            else {
                ostr << m_year << "/0" << m_mon << "/" << m_day;
            }
        }

        else {
            if (m_day<10) {
                ostr << m_year << "/" << m_mon << "/0" << m_day;
            }

            else {
                ostr << m_year << "/" << m_mon << "/" << m_day;
            }
        }
    }

    else {
        if (m_mon<10) {
            if (m_day<10) {
                ostr << m_year << "/0" << m_mon << "/0" << m_day << ", "
                     << m_hour << ":" << m_min;
            }

            else {
                ostr << m_year << "/0" << m_mon << "/" << m_day << ", "
                     << m_hour << ":" << m_min;
            }
        }

        else {
            if (m_day<10) {
                ostr << m_year << "/" << m_mon << "/0" << m_day << ", "
                     << m_hour << ":" << m_min;
            }

            else {
                ostr << m_year << "/" << m_mon << "/" << m_day << ", " << m_hour
                     << ":" << m_min;
            }
        }
    }

    return ostr;
}

std::istream& operator>>(std::istream& is, Date& date)
{
    date.read(is);
    return is;
}

std::ostream& operator<<(std::ostream& ostr, const Date& date)
{
    date.write(ostr);
    return ostr;
}
}

