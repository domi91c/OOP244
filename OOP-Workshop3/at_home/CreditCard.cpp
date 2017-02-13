#include "CreditCard.h"
#include <cstring>
#include <iostream>

namespace sict {
  using namespace std;
  CreditCard *cc = new CreditCard;

  void CreditCard::initialize(unsigned long long creditCardNumber, int instCode,
      int expiryYear, int expiryMonth,
      int numberInTheBack) {
    m_cardNumber = creditCardNumber;
    m_institutionCode = instCode;
    m_expiryYear = expiryYear;
    m_expiryMonth = expiryMonth;
    m_numberInTheBack = numberInTheBack;
    m_numberInTheBack = numberInTheBack;
  }

  void CreditCard::name(char cardHolderName[]) {
    strcpy(m_cardHolderName, cardHolderName);
  }

  void CreditCard::write(bool displayName, bool displayCardInfo) const {
    if (displayName && displayCardInfo) {
      writeName();
      cout << endl;
      writeCardInfo();
    } else if (displayName) {
      writeName();
    } else if (displayCardInfo) {
      writeCardInfo();
    }
  }

  void CreditCard::writeName() const {
    cout << "Cardholder: " << m_cardHolderName;
  }

  void CreditCard::writeCardInfo() const {
    cout << "Card Number: " << m_cardNumber << endl;
    cout << "Institution: " << m_institutionCode << endl;
    cout << "Expires: " << m_expiryMonth << "/" << m_expiryYear << endl;
    cout << "Number at the back: " << m_numberInTheBack;
  }

  bool CreditCard::isValid() {
    bool nameCheck = false, numCheck = false, instCheck = false,
         yearCheck = false, monthCheck = false, backNumCheck = false,
         finalCheck;

    if (strlen(m_cardHolderName)) {
      nameCheck = true;
    }

    if (m_cardNumber <= MAX_CARD_NUMBER && m_cardNumber >= MIN_CARD_NUMBER) {
      numCheck = true;
    }
    if (m_institutionCode <= MAX_INST_NUMBER &&
        m_institutionCode >= MIN_INST_NUMBER) {
      instCheck = true;
    }

    if (m_expiryYear <= MAX_EXP_YEAR && m_expiryYear >= MIN_EXP_YEAR) {
      yearCheck = true;
    }

    if (m_expiryMonth <= 12 && m_expiryMonth >= 1) {
      monthCheck = true;
    }

    if (m_numberInTheBack % 100 < 100) {
      backNumCheck = true;
    }

    if (nameCheck && numCheck && instCheck && yearCheck && monthCheck &&
        backNumCheck) {
      finalCheck = true;
    } else {
      finalCheck = false;
    }
    return finalCheck;
  }
}
