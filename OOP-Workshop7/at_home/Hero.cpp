// OOP244 Workshop 7 at_home
// File Hero.cpp
// Date 2017-04-03
// Author Dominic Nunes
// Student Number 016-183-121 
// Email dcnunes@myseneca.ca



#include <cstring>
#include <iostream>
#include "Hero.h"

using namespace std;

//////////////////////////////////////////////
// Default constructor
//
Hero::Hero()
{
    m_name[0] = '\0';
    m_health = 0;
    m_maximumHealth = 0;
    m_attack = 0;
}

///////////////////////////////////////////////////
// Constructor
// 
Hero::Hero(const char name[], unsigned maximumHealth, unsigned attack)
{
    strcpy(m_name, name);
    m_health = maximumHealth;
    m_attack = attack;
    m_maximumHealth = maximumHealth;
}

/////////////////////////////////////////////////////////
// 
// display function
// if verbose > 0 then prints additional information.
// set this variable at the top of this file
void Hero::display(ostream& out) const
{
    if (!isEmpty()) {
        out << m_name;
    }
}

/////////////////////////////////////////////////
// true if the Hero object is uninitialized
//
bool Hero::isEmpty() const
{
    return m_name[0]=='\0' && m_health==0 && m_maximumHealth==0 && m_attack==0;
}

/////////////////////////////////////////////////
// sets the Hero object's health back to full
//
void Hero::respawn()
{
    if (m_health==0) {
        m_health = m_maximumHealth;
    }
}

