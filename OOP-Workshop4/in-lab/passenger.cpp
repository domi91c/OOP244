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

  Passenger::~Passenger() {

  }

  // TODO: add the canTravelWith(...) function here
  bool Passenger::canTravelWith(const Passenger &passenger) const {
      bool ret = false;
      if (m_departureYear == passenger.m_departureYear && m_departureMonth == passenger.m_departureMonth &&
          m_departureDay == passenger.m_departureDay && m_destination == passenger.m_destination) {
          ret = true;
      }
      return ret;
  }

  // TODO: add the isEmpty() function here
  bool Passenger::isEmpty() const {
      bool ret = false;
      if (this->m_name[0] == '\0' || this->m_destination[0] == '\0' || this->m_departureYear == 0 ||
          this->m_departureMonth == 0 || this->m_departureDay == 0) {
          ret = true;
      }
      return ret;
  }

  // below is the member function already provided
  // TODO: read it and understand how it accomplishes its task
  void Passenger::display(bool nameOnly) const {
      if (false == this->isEmpty()) {
          cout << this->m_name;
          if (false == nameOnly) {
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