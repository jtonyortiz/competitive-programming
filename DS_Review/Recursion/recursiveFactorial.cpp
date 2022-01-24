//
//Author: James Ortiz   
//File: recursiveFactorial.cpp
//Description: Example of a recursive factorial function in C++
//Compile: g++ -std=c++11 -Wall recursiveFactorial.cpp -o exrec1

#include <iostream>
using namespace std;

//Recursive Factorial Function:
int recursiveFactorial(int n){
    if(n == 0)
        return 1;
    else
        return n * recursiveFactorial(n-1);
    
}

int main(void){
    int val = 0;
    val = recursiveFactorial(4);
    cout << "The value is: " << val << std::endl;

    return 0;
}