//
//Author: James Ortiz
//File: stringdemo.cpp
//Description: Demo of String class in C++ using the STL
//Compile: g++ -Wall -std=c++11 stringdemo.cpp -o strdemo


#include <string>
#include <iostream>

using namespace std;

int main(void){
    string s = "a dog";
    s += " is a dog";
    cout << s.find("dog");
    cout << s.find("dog", 3);

    if(s.find("doug") == string::npos){

    }

    cout << s.substr(7, 5);
    s.replace(2, 3, "frog");
    s.erase(6, 3);
    s.insert(0, "is ");
    if(s == "is a frog a dog"){}
    if(s < "is a frog a toad"){
    }
    if(s < "is a frog a cat"){

    }


    return 0;
}