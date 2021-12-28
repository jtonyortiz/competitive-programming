//
// Author: James Ortiz
// File: a_plus_b.cpp 
// Description: Calculate a+b
//

#include <iostream>
using namespace std;

long long int summation(long long int a, long long int b){
    return a + b;
}

int main(void){
    long long int a, b;

    cin >> a >> b;
    
    long long int sum = summation(a, b);

    cout << sum;

    return 0;
}


