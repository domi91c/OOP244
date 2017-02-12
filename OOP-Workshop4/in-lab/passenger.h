//TODO: add header guards here
#ifndef PASSENGER_H
#define PASSENGER_H

// TODO: holiday namespace here
namespace holiday {

  // TODO: declare the class Passenger here
  class Passenger {
    // TODO: add the class the attributes,
    //       the member function already provided,
    //       and the member functions that you must implement
    char m_name[32];
    char m_destination[32];
    int m_departureYear;
    int m_departureMonth;
    int m_departureDay;

  public:
    Passenger();
    Passenger(const char* name, const char* destination);
    ~Passenger();
    bool isEmpty() const;
    bool canTravelWith(const Passenger& passenger) const;
    void display(bool onlyNames = false) const;
  };

}

#endif