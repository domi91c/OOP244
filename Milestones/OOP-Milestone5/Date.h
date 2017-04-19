// OOP244 Milestone 5
// File Date.h
// Date 2017-04-17
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca

#ifndef ICT_DATE_H__
#define ICT_DATE_H__

#include <iostream>

using namespace std;
namespace ict {
#define    NO_ERROR   0  // No error - the date is valid.
#define    CIN_FAILED 1  // istream failed on accepting information using cin.
#define    YEAR_ERROR 2  // Year value is invalid.
#define    MON_ERROR  3  // Month value is invalid.
#define    DAY_ERROR  4  // Day value is invalid.
#define    HOUR_ERROR 5  // Hour value is invalid.
#define    MIN_ERROR  6  // Minute value is invalid.

// date and time management class
class Date {
private:
    int m_year;
    int m_mon;
    int m_day;
    int m_hour;
    int m_min;
    int m_readErrorCode;
    bool m_dateOnly;

    int value() const;
    void errCode(int errorCode);
    int mdays() const;
    void set();
    void set(int year, int mon, int day, int hour, int min);

public:
    // constructors
    Date();
    Date(int year, int mon, int day);
    Date(int year, int mon, int day, int hour, int min = 0);

    // operator overloads
    bool operator==(const Date&) const;
    bool operator!=(const Date&) const;
    bool operator<(const Date&) const;
    bool operator>(const Date&) const;
    bool operator<=(const Date&) const;
    bool operator>=(const Date&) const;

    // get m_readErrorCode
    int errCode() const;
    // check error status
    bool bad() const;
    // get m_dateOnly
    bool dateOnly() const;
    // set m_dateOnly
    void dateOnly(bool value);

    // istream  and ostream read and write methods
    istream& read(istream& is);
    ostream& write(ostream& os) const;

};

istream& operator>>(istream& is, Date& date);
ostream& operator<<(ostream& os, const Date& date);

}
#endif
