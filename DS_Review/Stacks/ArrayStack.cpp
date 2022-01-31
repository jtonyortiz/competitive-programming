//
//Author: James Ortiz
//File: ArrayStack.cpp
//Definition: Array Stack implementation in C++
//Compile: g++ -std=c++11 -Wall ArrayStack.cpp -o arrstack
//

#include <iostream> //I/O output 
#include <exception>
#include <stdexcept> //Exceptions
#include <string> //Useing string class for demo
using namespace std;

template<typename E>
class ArrayStack{
    enum{ DEF_CAPACITY = 200};              //default stack capacity
    public:
    ArrayStack(int cap = DEF_CAPACITY);      //constructor from capacity
    int size() const;                        //number of items in the stack
    bool empty() const;                      //is the stack empty
    const E& top() const throw();  //get the top element
    void push(const E& e) throw (); //push element onto stack
    void pop() throw();            //pop the stack
    private:
    E* S;         //Array of Stack elements
    int capacity; //Stack capcity
    int t;        //Index of the top of stack
};


//Class Constructor:
template<typename E> 
ArrayStack<E>::ArrayStack(int cap)
:S(new E[cap]), capacity(cap), t(-1){}

//Size function:
template<typename E> 
int ArrayStack<E>::size() const{
    return (t+1);
}

template <typename E> 
bool ArrayStack<E>::empty() const{
    return (t < 0);
}

template<typename E> 
const E& ArrayStack<E>::top() const throw(){
    if(empty()){
        throw std::invalid_argument("Top of empty stack");
    }else{
        return S[t];
    }
}

template<typename E>
void ArrayStack<E>::push(const E& e) throw(){
    if(size() == capacity) 
        throw std::invalid_argument("Push to full stack");
    S[++t] = e;
}

template<typename E>
void ArrayStack<E>::pop() throw(){
    if(empty()) 
        throw std::invalid_argument("Top of empty stack");
    --t;
}


int main(void){

    ArrayStack<int> A;
    A.push(7);
    A.push(13);
    cout << A.top() << endl;
    A.pop();
    A.push(9);
    cout << A.top() <<endl;
    A.pop();
    cout << A.top() << endl;

    ArrayStack<std::string> B(10);
    B.push("Bob");
    B.push("Alice");
    cout << B.top() << endl;
    B.pop();
    B.push("Eve");

    
    return 0;
}

