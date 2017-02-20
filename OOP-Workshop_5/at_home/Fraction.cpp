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


  // TODO: write the implementation of display function HERE
  void Fraction::display() const {
    if (isEmpty()) {
      cout << "Invalid Fraction Object!";
    } else if (denom == 1) {
      cout << num;
    } else {
      cout << num << "/" << denom;
    }
  }

  // TODO: write the implementation of isEmpty function HERE
  bool Fraction::isEmpty() const {
    return denom == -1;
  }

  // TODO: write the implementation of member operator+= function

  Fraction &Fraction::operator+=(Fraction f2) {
    if (isEmpty() || f2.isEmpty()) {
      denom = -1; // safe empty state
    } else {
      num = (num * f2.denom) + (denom * f2.num);
      denom = (denom * f2.denom);
    }

    return *this; // returns reference to current object

  }

  // TODO: write the implementation of member operator+ function HERE
  Fraction Fraction::operator+(Fraction f2) {
    Fraction fraction;
    if (isEmpty() || f2.isEmpty()) {
      fraction.denom = -1; // safe empty state
    } else {
      fraction.num = (num * f2.denom) + (denom * f2.num);
      fraction.denom = (denom * f2.denom);
    }

    return fraction;

  }

  // TODO: write the implementation of member operator* function HERE
  Fraction Fraction::operator*(Fraction f2) {
    Fraction fraction;
    if (isEmpty() || f2.isEmpty()) {
      fraction.denom = -1;
    } else {
      fraction.num = (num * f2.num);
      fraction.denom = (denom * f2.denom);
    }

    return fraction;

  }


  // TODO: write the implementation of member operator== function HERE
  Fraction Fraction::operator==(Fraction f2) {
  }



  // TODO: write the implementation of member operator!= function HERE

  // TODO: write the implementation of member operator double () function HERE

  // TODO: write the implementation of member operator double () function HERE


}
