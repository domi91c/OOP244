// OOP244 Workshop 7 at_home
// File SuperHero.h
// Date 2017-04-03
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca



#ifndef SUPERHERO_H
#define SUPERHERO_H

#include "Hero.h"

class SuperHero: public Hero {

    unsigned m_superPowerAttack;
    unsigned m_superPowerDefend;

public:

    // constructors  
    SuperHero();
    SuperHero(const char* name,
            unsigned health,
            unsigned attack,
            unsigned superPowerAttack,
            unsigned superPowerDefend);

    friend void apply_damage(SuperHero& A, SuperHero& B);

};

#endif