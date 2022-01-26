//
//Author: James Ortiz
//File: IterRevArr.cpp
//Description: IterRevArr.cpp
//Compile: g++ -std=c++11 -Wall IterRevArr.cpp -o itrevarr

#include <iostream>
#include <vector>
#include <utility>
using namespace std;


//Input: An array A and nonnegative integer indices i and j
//Output: The reversal of the elements in A starting at index i
//and ending at j
void IterativeReverseArray(std::vector<int> &A, int i, int j){
    while(i < j){
        std::swap(A[i],A[j]);
        i = i + 1;
        j = j - 1;
    }

    return;
}

int main(void){
    std::vector<int> a = {1, 2, 3, 4, 5};

    IterativeReverseArray(a, 0, 4);

    for(unsigned int i = 0; i < a.size(); i++){
        std::cout << a[i] << " ";
    }

    return 0;
}