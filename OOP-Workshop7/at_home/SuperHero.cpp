#include <iostream>



#include "SuperHero.h"


SuperHero::SuperHero() : Hero()
{
     
}
        
        
SuperHero::SuperHero( const char* name, unsigned maximumHealth, unsigned attack,
                unsigned superPowerAttack, unsigned superPowerDefend
        )  : Hero(name, maximumHealth, attack)
{ 
       
}



  
        
unsigned SuperHero::getAttack() const 
{ 
       
}
