// OOP244 Workshop 6 in_lab
// File Contact.h
// Date 2017-02-21
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca

#ifndef SICT_CONTACT_H__
#define SICT_CONTACT_H__

// TODO: add namespace here
namespace sict {
class Contact {
    char m_name[21];
    long long* m_phoneNumbers;
    int m_noOfPhoneNumbers;

    // TODO: add the default constructor here

    // TODO: add the constructor with parameters here

    // TODO: add the destructor here

    // TODO: add the display function here

    // TODO: add the isEmpty function here

   public:
    Contact(const Contact& other) = delete;
    Contact& operator=(const Contact& other) = delete;
};
}

#endif
