// OOP244 Workshop Milestone 1
// File Date.h
// Date 2017-04-04
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca



// compilation safegaurds
#ifndef ICT_DATE_H__
#define ICT_DATE_H__

#include <iostream>
// ict namespace 
namespace ict {


// Date defined Error values
#define    NO_ERROR   0  // No error - the date is valid.
#define    CIN_FAILED 1  // istream failed on accepting information using cin.
#define    YEAR_ERROR 2  // Year value is invalid.
#define    MON_ERROR  3  // Month value is invalid.
#define    DAY_ERROR  4  // Day value is invalid.
#define    HOUR_ERROR 5  // Hour value is invalid.
#define    MIN_ERROR  6  // Minute value is invalid.

class Date {
private:
    // member variables
    int m_year;
    int m_mon;
    int m_day;
    int m_hour;
    int m_min;
    int m_readErrorCode;
    bool m_dateOnly;

    // private methods
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
    bool operator==(const Date& D) const;
    bool operator!=(const Date& D) const;
    bool operator<(const Date& D) const;
    bool operator>(const Date& D) const;
    bool operator<=(const Date& D) const;
    bool operator>=(const Date& D) const;

    // methods
    int errCode() const;
    bool bad() const;
    bool dateOnly() const;
    void dateOnly(bool value);

    // istream  and ostream read and write methods
    std::istream& read(std::istream& is);
    std::ostream& write(std::ostream& ostr) const;

};

// operator << and >> overload prototypes for cout and cin
std::istream& operator>>(std::istream& is, Date& D);
std::ostream& operator<<(std::ostream& ostr, const Date& D);

}
#endif
 
 