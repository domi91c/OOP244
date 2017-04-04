// OOP244 Workshop 7: Derived Classes
// File w7_athome.cpp
// Version 1.0
// Date 2017/03/11
// Author       Hasan Murtaza
// Description
//       This file demonstrates the client module of w7
/////////////////////////////////////////////////////

#include <iostream>
#include "Hero.h"
#include "SuperHero.h"
#include "fight.h"

using namespace std;

void line(int width)
{
  for (int i=0;i<width;i++)
  {
    cout << "-";
  }
}

 
int main ()
{
  
  cout << endl;
  line(60);
  
  cout << endl << "Greek Heros";
  Hero hercules         ("Hercules",  32, 4);
  Hero theseus          ("Theseus",   14, 5);
  Hero oddyseus         ("Odysseus",  15, 3);
  Hero ajax             ("Ajax",      17, 5);
  Hero achilles         ("Achilles",  20, 6);
  Hero hector           ("Hector",    30, 5);
  Hero atalanta         ("Atalanta",  10, 3);
  Hero hippolyta        ("Hippolyta", 10, 2);  
    

 
  cout << endl << "Quarter Finals" << endl;
  const Hero& greek_winner1 = achilles * hector; 
  const Hero& greek_winner2 = hercules * theseus;
  const Hero& greek_winner3 = oddyseus * ajax;
  const Hero& greek_winner4 = atalanta   * hippolyta;
  
  cout << endl << "Semi Finals" << endl;
  const Hero& greek_winner_semifinal1 = greek_winner1  * greek_winner2;
  const Hero& greek_winner_semifinal2 = greek_winner3  * greek_winner4;

  cout << endl << "Finals" << endl;
  const Hero& greek_final = greek_winner_semifinal1 * greek_winner_semifinal2;





  line(60);
  cout << endl << "Comic book SuperHeros"; 
  
  SuperHero superman    ("Superman",  50, 9, 10, 9) ;
  SuperHero hulk        ("The_Hulk",   70, 6, 20, 3) ;
  SuperHero wonderwoman ("WonderWoman",   80, 5, 15, 10) ;
  SuperHero raven       ("Raven",   30, 10, 12, 5) ;
  
  cout << endl << "Semi Finals" << endl;
  const SuperHero& comic_winner1 = superman * hulk;
  const SuperHero& comic_winner2 = wonderwoman * raven;
  cout << endl << "Finals" << endl;
  const SuperHero& comic_final = comic_winner1 * comic_winner2;
  

  line(60);
  cout << endl << "Best Greeks Hero vs Best Comic Book SuperHero" << endl;
  greek_final * comic_final;

  

}
