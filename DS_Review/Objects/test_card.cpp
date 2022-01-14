//
//Author: James Ortiz
//File: test_card.cpp
//Description: Driver .cpp file for the CreditCard class.
//Compile: g++ -Wall -std=c++11 test_card.cpp -o test_card
//


#include <vector>
#include "credit_card.h"
#include "credit_card.cpp"
using namespace std;

void testCard(){
    vector<CreditCard*> wallet(10);

    wallet[0] = new CreditCard("5391 0375 9387 5309", "John Bowman", 2500);
    wallet[1] = new CreditCard("3485 0399 3395 1954", "John Bowman", 3500);
    wallet[2] = new CreditCard("6011 4902 3294 2994", "John Bowman", 5000);

    for (int j = 1; j <= 16; j++)
    {
        wallet[0]->chargeIt(double(j));
        wallet[1]->chargeIt(2 * j);
        wallet[2]->chargeIt(double(3 * j));
    }

    cout << "Card Payments:\n";
    for(int i=0; i < 3; i++){
        cout << *wallet[i];
        while(wallet[i]->getBalance() > 100.0){
            wallet[i]->makePayment(100.0);
            cout << "New Balance = " << wallet[i]->getBalance() << "\n";
        }
        cout << "/n";
        delete wallet[i];
    }
}
 

int main(void){
    testCard();
    return EXIT_SUCCESS;
}