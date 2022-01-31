//
//Author: James Anthony Ortiz
//File: ParenMatchAlgo.cpp
//Description: Algorithm for checking if grouped symbols mach correctly
//Compile: g++ -std=c++11 -Wall ParenMatchAlgo.cpp
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


//Input: An array X of n tokens, each of which is either a 
//grouping symbol, a variable, an arithmetic operator, or a number

//Output: True if and only if all of the grouping smybols in X match

bool ParenMatch(std::vector<char> &V, int n){
    std::stack<char> s;

    for(int i = 0; i < V.size(); i++){
        if(V[i] == '{' || V[i] == '(' || V[i] == '['){
            s.push(V[i]);
        }
        else if(V[i] == '}' || V[i] == ')' || V[i] == ']'){
            if(s.empty()){
                return false;
            }
            s.pop();
        }

        if(s.empty()){
            return true;
        }else {
            return false;
        }
    }

}
