#include "Fraction.h"

using namespace std;

namespace sict{
    Fraction::Fraction(){  
            denom =-1;              // safe empty state
    }
    
    Fraction::Fraction(int n, int d) // n: numerator, d: denominator
    { 
        if(n >= 0 && d > 0){
            num = n;
            denom = d;
            reduce();
        }
        else 
            denom =-1;              // set to safe empty state
    }

    int Fraction::gcd()                                        // returns the greatest common divisor of num and denom 
    {
        int mn = min();                                        // min of num and denom
        int mx = max();                                        // mX of num and denom

        for (int x=mn ; x > 0 ; x--)                           // find the greatest common divisor
            if( mx % x == 0 &&  mn % x == 0)
                return x;
        return 1;

    } 

    void Fraction::reduce()                                         // simplify the Fraction number  
    {
        int tmp = gcd();
        num /= tmp;
        denom /= tmp;
    }

    int Fraction::max ()
    {
        return (num >= denom) ? num : denom; 
    }

    int Fraction::min()
    {
        return (num >= denom) ? denom : num; 
    }
  
    // TODO: Copy-paste the implementation of member isEmpty function from the in_lab part answer HERE

    // TODO: Copy-paste the implementation of member display function from the in_ab part answer HERE


    // TODO: Copy-paste the implementation of member operator+= function from the in_lab part answer HERE

    // TODO: Copy-paste the implementation of member operator+ function from the in_ab part answer HERE

    // TODO: Copy-paste the implementation of member operator* function from the in_lab part answer HERE


    // TODO: write the implementation of member operator== function HERE

    // TODO: write the implementation of member operator!= function HERE

    // TODO: write the implementation of member operator double () function HERE

    // TODO: write the implementation of member operator double () function HERE
    

}