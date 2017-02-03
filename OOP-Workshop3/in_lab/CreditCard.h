#include <iostream>

#ifndef CREDITCARD_H
#define CREDITCARD_H

#define MAX_NAME_LENGTH 40
#define MIN_INST_NUMBER 100
#define MAX_INST_NUMBER 999
#define MIN_EXP_YEAR 2017
#define MAX_EXP_YEAR 2037
#define MIN_CARD_NUMBER 4000000000000000
#define MAX_CARD_NUMBER 4000999999999999

namespace sict {

class CreditCard {
   public:
    void initialize(unsigned long long creditCardNumber, int instCode,
                    int expiryYear, int expiryMonth, int numberInTheBack);
    void name(const char cardHolderName[]);
    void write();
    bool isValid();

   private:
    char m_cardHolderName[MAX_NAME_LENGTH];
    unsigned long long m_cardNumber;
    int m_institutionCode;
    int m_expiryYear;
    int m_expiryMonth;
    int m_numberInTheBack;
};
}

#endif

