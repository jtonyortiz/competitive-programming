//
//Author: James Ortiz
//File: credit_card.h
//Description: Header file for credit_card.cpp 
//

#ifndef CREDIT_CARD_H
#define CREDIT_CARD_H

#include <string>
#include <iostream>

class CreditCard{
    public: 
    CreditCard(const std::string& no, const std::string& nm, int lim, double bal = 0);

    std::string getNumber() const {return number;}
    std::string getName() const {return name;}
    double getBalance() const {return balance;}
    int getLimit() const {return limit; }

    bool chargeIt(double price);        //Make a charge
    void makePayment(double payment);   //Make a payment
    private:
    std::string number;     //credit-card number
    std::string name;       //card-owner's name
    int limit;              //credit-card limit
    double balance;         //credit-card balance

};

std::ostream& operator<< (std::ostream& out, const CreditCard& c);

#endif