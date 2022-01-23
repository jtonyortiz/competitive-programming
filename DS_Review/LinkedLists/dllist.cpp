//
//Author: James Ortiz
//File: dllist.cpp
//Description: Doubly-Linked List implementation in C++
//Compile: g++ -Wall -std=c++11 dllist.cpp -o dllist
//

#include <iostream>
#include <string>
using namespace std;

typedef string Elem;
class DNode{
    private:
    Elem elem;
    DNode* prev;
    DNode* next;
    friend class DLinkedList;
};

class DLinkedList{
    public:
    DLinkedList(); //constructor
    ~DLinkedList(); //destructor
    bool empty() const; //is the list empty?
    const Elem& front() const; //get front elemt
    const Elem& back() const; //get back elemt
    void addFront(const Elem& e); //add to the front
    void addBack(const Elem& e); //add to the back
    void removeFront(); //remove from front
    void removeBack();  //remove from back
    void print(); //Print items in Doubly Linked List:
    private: 
    //List Sentinels:
    DNode* header; 
    DNode* trailer;
    protected:
    //Local Utilities
    void add(DNode* v, const Elem& e); //Insert new node before v
    //Remove node v
    void remove(DNode* v);
};

DLinkedList::DLinkedList(){
    //Create Sentinels:
    header  = new DNode;
    trailer = new DNode;

    //Have the Sentinels point to each other:
    header->next = trailer;
    trailer->prev = header;
}

DLinkedList::~DLinkedList(){
    while(!empty()){
        removeFront();
    }
    delete header;
    delete trailer;
}

//Check if the list is empty
bool DLinkedList::empty() const{
    return header->next == trailer;
}

const Elem& DLinkedList::front() const{
    return header->next->elem;
}

const Elem&DLinkedList::back() const{
    return trailer->prev->elem;
}

//Insert new node before v
void DLinkedList::add(DNode* v, const Elem& e){
    DNode* u = new DNode; //Create new node for e
    u->elem = e;
    u->next = v;    //link u in between v
    u->prev = v->prev; //and v->prev
    v->prev->next = v->prev = u;
}

//Add to the front of the list:
void DLinkedList::addFront(const Elem& e){
    add(header->next, e);
}

//Add to the back of the list:
void DLinkedList::addBack(const Elem& e){
    add(trailer, e);
}


//Remove node v:
void DLinkedList::remove(DNode * v){
    DNode* u = v->prev; //Predecessor
    DNode* w = v->next;  //Successor
    //Unlink v from list:
    u->next = w;
    w->prev = u;
    delete v;
}

//Remove element from front
void DLinkedList::removeFront(){
    remove(header->next);
}

//Remove element from the back
void DLinkedList::removeBack(){
    remove(trailer->prev);
}

void DLinkedList::print(){
    while(header != trailer){
        std::cout << header->elem << std::endl;
        header = header->next;
    }
}

int main(){
    DLinkedList s; // Create linked list:
    s.addFront("Green");
    s.addFront("Blue");
    s.addFront("Purple");
    s.addFront("Orange");

    //Print values:
    s.print();

    //Print values:
    std::cout << s.empty() << std::endl;
    return 0;
}