// OOP244 Workshop 7 at_home
// File fight.cpp
// Date 2017-04-03
// Author Dominic Nunes
// Student Number 016-183-121 
// Email dcnunes@myseneca.ca


///////////////////////////////
//  Workshop 7
// Derived classes
//
// fight.cpp for at-home portion
// by Hasan Murtaza
// 1.0
// Copyright 2017 Seneca College


#include <iostream>
#include "Hero.h"
#include "SuperHero.h"
#include "fight.h"

using namespace std;

//////////////////////
// Global helper function
// compute the damage that A inflicts on B 
// and of B on A
//
void apply_damage(Hero& A, Hero& B)
{
    if ((unsigned) A.m_health>=B.m_attack) {
        A.m_health -= B.m_attack;
    }
    else {
        A.m_health = 0;
    }
    if ((unsigned) B.m_health>=A.m_attack) {
        B.m_health -= A.m_attack;
    }
    else {
        B.m_health = 0;
    }
}

//////////////////////
// Global helper function
// compute the damage that A inflicts on B 
// and of B on A
//
void apply_damage(SuperHero& A, SuperHero& B)
{
    if (A.m_health>=0 && B.m_health>=0) {
        int damage_A = A.m_superPowerAttack-B.m_superPowerDefend;
        B.m_health = B.m_health-damage_A;
        int damage_B = B.m_superPowerAttack-A.m_superPowerDefend;
        A.m_health = A.m_health-damage_B;
    }
}

//////////////////////
// Global helper operator
// rather than type in fight(hercules, theseus), we use an operator
// so you can type in hercules * theseus
//
// returns a reference to the winner object
// 
// so that if hercules is stronger, 
// (hercules * theseus) == hercules
// will be true.
// 
// note the inputs are const, so that you can be sure that the heros will be unharmed during the fight.
const Hero& operator*(const Hero& first, const Hero& second)
{
    // Display the names of the people fighting

    cout << "AncientBattle! ";
    first.display(cout);
    cout << " vs ";
    second.display(cout);
    cout << " : ";

    // Since this is a fair tournament, we want the input
    // arguments to be constant (so that a and b are not modified
    // during the fight.
    // So we make a copy of the objects

    Hero A = first;
    Hero B = second;
    const Hero* winner = nullptr;

    unsigned int rounds = 0;
    // loop while both are still alive
    while (A.isAlive() && B.isAlive() && rounds<100) {
        rounds++;
        apply_damage(A, B);
    }

    // if we got here, then one Hero is dead, or it was a draw.
    bool draw = A.isAlive() && B.isAlive();

    // if it was a draw, then we decide by tossing an unfair coin and always
    // declare that A was the winner. 
    if (draw) {
        winner = &first;
    }
    else if (A.isAlive()) {
        winner = &first;
    }
    else {
        winner = &second;
    }

    cout << "Winner is ";
    winner->display(cout);
    cout << " in " << rounds << " rounds." << endl;
    return *winner;

}

//////////////////////
// Global helper operator
// rather than type in fight(hercules, theseus), we use an operator
// so you can type in hercules * theseus
//
// returns a reference to the winner object
// 
// so that if hercules is stronger, 
// (hercules * theseus) == hercules
// will be true.
// 
// note the inputs are const, so that you can be sure that the heros will be unharmed during the fight.
const SuperHero& operator*(const SuperHero& first, const SuperHero& second)
{
    // Display the names of the people fighting
    cout << "SuperFight! ";
    first.display(cout);
    cout << " vs ";
    second.display(cout);
    cout << " : ";

    // Since this is a fair tournament, we want the input 
    // arguments to be constant (so that a and b are not modified
    // during the fight.
    // So we make a copy of the objects
    SuperHero A = first;
    SuperHero B = second;
    const SuperHero* winner = nullptr;

    unsigned int rounds = 0;
    // loop while both are still alive
    while (A.isAlive() && B.isAlive() && rounds<100) {
        rounds++;
        apply_damage(A, B);
    }

    // if we got here, then one Hero is dead, or it was a draw.
    bool draw = A.isAlive() && B.isAlive();

    // if it was a draw, then we decide by tossing an unfair coin and always
    // declare that A was the winner. 
    if (draw) {
        winner = &first;
    }
    else if (A.isAlive()) {
        winner = &first;
    }
    else {
        winner = &second;
    }

    cout << "Winner is ";
    winner->display(cout);
    cout << " in " << rounds << " rounds." << endl;
    return *winner;
}
