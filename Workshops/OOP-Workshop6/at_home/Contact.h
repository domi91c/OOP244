// OOP244 Workshop 6 in_lab
// File Contact.h
// Date 2017-03-08
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca

#ifndef COMMUNICATION_CONTACT_H__
#define COMMUNICATION_CONTACT_H__

// TODO: add namespace here
namespace communication {
  class Contact {
    char m_name[21];
    long long *m_phoneNumbers;
    int m_noOfPhoneNumbers;

  public:
    // TODO: add the default constructor here
    Contact();

    // TODO: add the constructor with parameters here
    Contact(const char *name, const long long *phoneNumbers, const int noOfPhoneNumbers);

    // copy constructor
    Contact(const Contact &other);

    // TODO: add the destructor here
    ~Contact();

    // TODO: add the display function here
    bool display() const;

    // TODO: add the isEmpty function here
    bool isEmpty() const;


    Contact &operator=(const Contact &other);

    void addPhoneNumber(long long phoneNumber);


  };

}
#endif




