// OOP244 Workshop 7 at_home
// File SuperHero.cpp
// Date 2017-04-03
// Author Dominic Nunes
// Student Number 016-183-121 
// Email dcnunes@myseneca.ca



#include <iostream>
#include "SuperHero.h"
#include "Hero.h"

SuperHero::SuperHero()
        :Hero()
{

    m_superPowerAttack = 0;
    m_superPowerDefend = 0;

}

SuperHero::SuperHero(const char* name, unsigned maximumHealth, unsigned attack,
        unsigned superPowerAttack, unsigned superPowerDefend
)
        :Hero(name, maximumHealth, attack)
{

    m_superPowerAttack = superPowerAttack;
    m_superPowerDefend = superPowerDefend;

}

 
        
