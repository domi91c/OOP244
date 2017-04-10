// OOP244 Workshop 2
// File kingdom.cpp
// Date 2017-01-23
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca
//

// TODO: include the necessary headers
#include "kingdom.h"
#include <iostream>
#include <string>

// TODO: the westeros namespace
namespace westeros {
// TODO:definition for display(...)
  void display(Kingdom &kingdom) {
      std::cout << kingdom.m_name << ", population " << kingdom.m_population << end;
  }
}
