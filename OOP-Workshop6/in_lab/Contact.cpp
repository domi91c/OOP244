#include <iostream>
#include "Contact.h"

using namespace std;

namespace communication {
  Contact::Contact(const Contact &other) {}

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
/*
  Contact &Contact::operator=(const Contact &other) {
      if (this != &other) {
          m_name[0] = other.m_name[0];
          m_phoneNumbers = other.m_phoneNumbers;

          delete[] m_phoneNumbers;

          if (other.m_phoneNumbers != nullptr) {
              m_phoneNumbers = new long long[m_noOfPhoneNumbers];
              for (int i = 0; i < m_noOfPhoneNumbers; i++)
                  m_phoneNumbers[i] = other.m_phoneNumbers[i];
          } else {
              m_phoneNumbers = nullptr;
          }
      }
      return *this;

  }

  void Contact::addPhoneNumber(long long phoneNumber) {
  }*/

}

