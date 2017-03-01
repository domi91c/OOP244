// OOP244 Workshop 6 in_lab
// File Contact.h
// Date 2017-02-21
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca

#ifndef CONTACT_H__
#define CONTACT_H__

// TODO: add namespace here
namespace communication {
  class Contact
  {
    char m_name[21];
    long long* m_phoneNumbers;
    int m_noOfPhoneNumbers;
  public:
    // TODO: add the default constructor here
    Contact();
    // TODO: add the constructor with parameters here
    Contact(const char* name, const long long* phoneNumbers, const int noOfPhoneNumbers);
    // TODO: add the destructor here
    ~Contact();
    // TODO: add the display function here
    bool display() const;
    // TODO: add the isEmpty function here
    bool isEmpty() const;

  public:
    Contact(const Contact& other); // Copy Constructor
    Contact& operator=(const Contact& other); // Copy Assignment Operator
    void addPhoneNumber(long long phoneNumber); // Modifier
  };

}
#endif




