//
//Author: James Ortiz
//File: BinaryFib.cpp
//Description: Binary Recurive form of Fiboancci Sequence
//Compile: g++ -std=c++11 -Wall BinaryFib.cpp -o binfib

#include <iostream>
using namespace std;

int BinaryFib(int k){
    if ( k <= 1){
        return k;
    }else{
        return BinaryFib(k-1) + BinaryFib(k-2);
    }
}

int main(void){

    int val = BinaryFib(1);
    cout << "Calculating up to the 8th Fibonacci Number: " << val << endl;


    return 0;
}