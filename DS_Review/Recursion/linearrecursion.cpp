//
//Author: James Ortiz
//File: linearrecursion.cpp
//Description: Example of linear recursion through
//a function that sums up the elements of an array
//Compile: g++ -std=c++11 -Wall linearrecursion.cpp -o lrec


#include <iostream> //Used for I/O
#include <vector>   //Used for vector implementation
using namespace std;


//Input: An integer array A and an integer n >= 1, such that A 
//has at least n elements 
//Output: The sum of the first n integers in A
int LinearSum(std::vector<int> &A, int n){
    //Base Case: if n == 1 return first element, and terminate
    if(n == 1){
        return A[0];
    }
    else{
        //Otherwise, Recurisvely call LinearSum() function:
        return LinearSum(A, n-1) + A[n-1];
    }
}

//Driver Source Code:
int main(void){

    //Sample int vector:
    std::vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    //Pass vector into function,My curiosity with software development started out in grade school. As a pragmatic learner, I began picking up ANSI C development by my own interest and later began using the WIN32 API for Windows applications. Eventually I got bored of Windows ME and I was then introduced to Ubuntu Linux at a local LUG (Linux User Group) gathering at a local library in 2005. I started out by building a few small console apps such as a tetris game, and a calculator. My access to the internet was scarce as I still did not have internet from home, so I learned on my own by borrowing books from a public library along with useing the compilers and man pages provided by the Linux OS itself. Now, being a graduate in this field, my understanding of Software Development has changed dramatically ever since I have began to study Computer Science from an academic perspective, and not just seeing programming as a daily hobby, ultimately preparing me for work in industry. and number of elements
    //to print the result:

    std::cout << "The sum of the array is: " << LinearSum(a,10) << std::endl;

    return 0;
}