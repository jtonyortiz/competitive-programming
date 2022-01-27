//Author: James Ortiz
//File: BinaryRec.cpp
//Description: An example of binary recursion by calculating
//the binary sum in C++
//Compile: g++ -std=c++11 -Wall BinaryRec.cpp -o BinRec
//

#include <vector>
#include <iostream>
using namespace std;

//
//Input: An array A and integers i and n
//Output: The sum of the n integers in A 
//starting at index i
int BinarySum(std::vector<int> &A, int i, int n){
    if (n == 1){
        return A[1];
    }else{
        return BinarySum(A, i, n/2) + BinarySum(A, i + n/2, n/2);
    }
}

int main(void){

    std::vector<int> v = {1, 2, 3, 4, 5};
    int result  = BinarySum(v, 0, 5);

    std::cout << "The sum of the elements in the vector are: " << result << std::endl;

    return 0;
}