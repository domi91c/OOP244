// OOP244 Workshop 7 at_home
// File Hero.h
// Date 2017-04-03
// Author Dominic Nunes
// Student Number 016-183-121
// Email dcnunes@myseneca.ca



#ifndef HERO_H
#define HERO_H

#include <iostream>

class Hero {
    char m_name[41];
    unsigned m_attack;
    unsigned m_maximumHealth;
    bool isEmpty() const;

protected:
    int m_health;
public:
    Hero();
    Hero(const char name[], unsigned maximumHealth, unsigned attack);

    void respawn();
    bool isAlive() const { return m_health>0; }

    // display function
    void display(std::ostream&) const;

    friend void apply_damage(Hero& A, Hero& B);
};

#endif
