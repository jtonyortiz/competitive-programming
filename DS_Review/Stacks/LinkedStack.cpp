//
//Author: James Ortiz
//File: LinkedStack.cpp
//Description: Implementation of a Stack with a Linked List
//Compile: g++ -std=c++11 -Wall LinkedStack.cpp -o LStack
//

#include <iostream>
#include <stdexcept>
#include <string>
#include "SLinkedList.cpp"
using namespace std;

typedef string Elem;
class LinkedStack{
    public: 
    LinkedStack();                      //Constructor
    int size() const;                   //get number of items in the stack
    bool empty() const;                 //check if the stack is empty
    const Elem& top() const throw();    //obtain top element
    void push(const Elem& e);           //push element onto stack
    void pop() throw ();                //pop stack

    //Member data:
    private:
    SLinkedList<Elem> S; //Linked-list of elements
    int n;              // number of elements
};

//Consructor
LinkedStack::LinkedStack(): S(), n(0){

}

//Size of Stack:
int LinkedStack::size() const{
    return n;
}

//Check if the Stack is empty:
bool LinkedStack::empty() const{
    return n == 0;
}

//Get element at top of the stack
const Elem& LinkedStack::top() const throw(){
    if(empty()){
        throw invalid_argument("Top of empty stack");
    }
    else{
        return S.front();
    }
}

//Push element onto the stack:
void LinkedStack::push(const Elem& e){
    ++n;
    S.addFront(e);
}

//Pop element from the stack:
void LinkedStack::pop() throw(){
    if(empty()){
        throw invalid_argument("Pop from empty stack");
    }else{
        --n;
        S.removeFront();
    }
}

