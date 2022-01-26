//Author: James Ortiz
//File: BinaryRec.cpp
//Description: An example of binary Recursion by calculating
//the binary sum 
//Compile: g++ -std=c++11 -Wall BinaryRec.cpp -o BinRec
//

#include <vector>
#include <iostream>
using namespace std;

int BinarySum(std::vector<int> &A, int i, int n){
    if (n == 1){
        return A[1];
    }else{
        return BinarySum(A, i, n/2) + BinarySum(A, i + n/2, n/2);
    }
}

int main(void){

    
    return 0;
}