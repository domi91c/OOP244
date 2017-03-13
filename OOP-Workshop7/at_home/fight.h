#ifndef FIGHT_H
#define FIGHT_H
 

const SuperHero & operator* (const SuperHero & a, const SuperHero & b);
const Hero & operator* (const Hero & a, const Hero & b);
void apply_damage (SuperHero& A, SuperHero& B);
void apply_damage (Hero& A, Hero& B);


#endif
