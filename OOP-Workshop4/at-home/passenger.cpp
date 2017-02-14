// OOP244 Workshop 4 at_home
// File passenger.cpp
// Date 2017-02-13
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca
//

// TODO: add your headers here
#include <iostream>
#include "passenger.h"
#include <cstring>

// TODO: add the namespaces that you will be using here
using namespace std;

// TODO: holiday namespace here
namespace holiday {

  // TODO: add the default constructor here
  Passenger::Passenger() {
      m_name[0] = '\0';
      m_destination[0] = '\0';
      m_departureYear = 0;
      m_departureMonth = 0;
      m_departureDay = 0;

  }

  // TODO: add the constructor with 2 parameters here
  Passenger::Passenger(const char *name, const char *destination) {
      if (name == nullptr || name[0] == '\0') {
          m_name[0] = '\0';
      } else {
          strcpy(m_name, name);
      }

      if (destination == nullptr || destination[0] == '\0') {
          m_destination[0] = '\0';
      } else {
          strcpy(m_destination, destination);
      }

      m_departureYear = 1;
      m_departureMonth = 7;
      m_departureDay = 2017;
  }

  Passenger::Passenger(const char *name, const char *destination, int departureYear, int departureMonth,
                       int departureDay) {

      if (name == nullptr || name[0] == '\0') {
          m_name[0] = '\0';
      } else {
          strcpy(m_name, name);
      }

      if (destination == nullptr || destination[0] == '\0') {
          m_destination[0] = '\0';
      } else {
          strcpy(m_destination, destination);
      }

      if (departureYear < 2017 || departureYear > 2020) {
          m_departureYear = 0;
      } else {
          m_departureYear = departureYear;
      }
      if (departureMonth < 1 || departureMonth > 12) {
          m_departureMonth = 0;
      } else {
          m_departureMonth = departureMonth;
      }

      if (departureDay < 1 || departureDay > 31) {
          m_departureDay = 0;
      } else {
          m_departureDay = departureDay;
      }
  }

  Passenger::~Passenger() {

  }


  void Passenger::travelWith(const Passenger *arrPassengers, int size) {
      int travelPartnerCount = 0;
      Passenger *travelPartners = new Passenger[size];

      for (int i = 0; i < size; ++i) {
          if (canTravelWith(arrPassengers[i])) {
              travelPartners[travelPartnerCount] = arrPassengers[travelPartnerCount];
              travelPartnerCount++;
          }
      }

      if (travelPartnerCount == 0) {
          cout << "Nobody can join ";
          display(true);
          cout << " on vacation!" << endl;
      } else {
          display(true);
          cout << " will be accompanied by ";
          for (int j = 0; j < travelPartnerCount; ++j) {
              if (j < travelPartnerCount - 1) {
                  travelPartners[j].display(true);
                  cout << ", ";
              } else {
                  travelPartners[j].display(true);
                  cout << "." << endl;
              }

          }
      }

  }

// TODO: add the canTravelWith(...) function here
  bool Passenger::canTravelWith(const Passenger &passenger) const {
      bool ret =
          m_departureYear == passenger.m_departureYear && m_departureMonth == passenger.m_departureMonth &&
          m_departureDay == passenger.m_departureDay && !strcmp(m_destination, passenger.m_destination);
      return ret;
  }

// TODO: add the isEmpty() function here
  bool Passenger::isEmpty() const {
      bool ret = m_name[0] == '\0' || m_destination[0] == '\0' || m_departureYear == 0 ||
                 m_departureMonth == 0 || m_departureDay == 0;
      return ret;
  }

// below is the member function already provided
// TODO: read it and understand how it accomplishes its task
  void Passenger::display(bool nameOnly) const {
      if (!this->isEmpty()) {
          cout << this->m_name;
          if (!nameOnly) {
              cout << " will travel to " << this->m_destination << ". "
                   << "The journey will start on "
                   << this->m_departureYear << "-"
                   << this->m_departureMonth << "-"
                   << this->m_departureDay
                   << "." << endl;
          }
      } else {
          cout << "Invalid passenger!" << endl;
      }
  }


}
