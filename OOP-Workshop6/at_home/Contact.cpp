// OOP244 Workshop 6 at_home
// File Contact.cpp
// Date 2017-03-08
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca

#include <iostream>
#include "Contact.h"

using namespace std;

namespace communication {

  Contact::Contact() {
      m_name[0] = '\0';
      m_phoneNumbers = nullptr;
      m_noOfPhoneNumbers = 0;
  }

  Contact::Contact(const char *name, const long long *phoneNumbers, const int noOfPhoneNumbers) {
      m_name[0] = '\0';
      m_phoneNumbers = nullptr;
      m_noOfPhoneNumbers = 0;

      if (name != '\0' && strcmp(name, "") != 0) {
          strncpy(m_name, name, 20);
          m_name[20] = '\0';
          m_noOfPhoneNumbers = noOfPhoneNumbers;
      }

      if (phoneNumbers) {
          m_phoneNumbers = new long long[m_noOfPhoneNumbers];
          for (int i = 0; i < m_noOfPhoneNumbers; i++) {
              m_phoneNumbers[i] = phoneNumbers[i];
          }
      }

  }

  Contact::~Contact() {
      delete[] m_phoneNumbers;
  }


  bool Contact::isEmpty() const {
      return m_name[0] == '\0' || strcmp(m_name, "") == 0;
  }

  bool Contact::display() const {
      if (isEmpty()) {
          cout << "Empty contact!" << endl;
      } else {
          cout << m_name << endl;
          for (int i = 0; i < m_noOfPhoneNumbers; i++) {
              if (10000000000 <= m_phoneNumbers[i] &&
                  m_phoneNumbers[i] <= 999999999999) {
                  cout << "(+" << m_phoneNumbers[i] / 10000000000 << ") "
                       << m_phoneNumbers[i] % 10000000000 / 10000000 << " "
                       << m_phoneNumbers[i] % 10000000 / 10000 << "-"
                       << m_phoneNumbers[i] % 10000000 % 10000 << endl;
              }
          }
      }
      return true;

  }

  // Copy Constructor.
  Contact::Contact(const Contact &other) {

      // Shallow copies.
      m_name[0] = other.m_name[0];
      m_phoneNumbers = other.m_phoneNumbers;
      m_noOfPhoneNumbers = other.m_noOfPhoneNumbers;
      if (other.m_phoneNumbers != nullptr) {
          m_phoneNumbers = new long long[m_noOfPhoneNumbers]; // Allocate new memory if not equal to the nullptr.
          for (int i = 0; i < m_noOfPhoneNumbers; i++) {
              m_phoneNumbers[i] = other.m_phoneNumbers[i];  // Copy resource data.
          }
      } else {
          m_phoneNumbers = nullptr;
      }
  }

  // Copy assignment operator.
  Contact &Contact::operator=(const Contact &other) {

      if (this != &other) {

          // Shallow copy non-resource variables.
          m_name[0] = other.m_name[0];
          *m_phoneNumbers = *other.m_phoneNumbers;
          m_noOfPhoneNumbers = other.m_noOfPhoneNumbers;
          // Deallocate previously allocated dynamic memory.
          delete[]  m_phoneNumbers;

          // Allocate new dynamic memory if not equal to the nullptr.
          if (other.m_phoneNumbers != nullptr) {
              m_phoneNumbers = new long long[m_noOfPhoneNumbers];
              // Copy the resource data.
              for (int i = 0; i < m_noOfPhoneNumbers; i++)
                  m_phoneNumbers[i] = other.m_phoneNumbers[i];
          } else {
              m_phoneNumbers = nullptr;
          }
      }
      return *this;
  }

  void Contact::addPhoneNumber(long long phoneNumber) {
      long long *temp = new long long[this->m_noOfPhoneNumbers];

      for (int i = 0; i < m_noOfPhoneNumbers; i++) {
          temp[i] = m_phoneNumbers[i];
      }
      temp[m_noOfPhoneNumbers] = phoneNumber;
      this->m_phoneNumbers = temp;
      this->m_noOfPhoneNumbers++;
      cout << *this->m_phoneNumbers << endl;
  }

}

