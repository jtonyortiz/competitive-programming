//
//Author: James Ortiz
//File: gensinglylinkedlist.cpp
//Description: Generic version of a singly linked list
//Compile: g++ -std=c++11 -Wall gensinglylinkedlist.cpp -o gsll

#include <string>
#include <iostream>
using namespace std;

template <typename E>
class SLinkedList;

template <typename E>
class SNode{
private:
    E elem;
    SNode<E>* next;
    friend class SLinkedList<E>;
};

template <typename E>
class SLinkedList{  //a generic singly linked list
    public:
    SLinkedList();  //empty list constructor
    ~SLinkedList(); //destructor
    bool empty() const; //check if the list is empty
    const E& front() const; //return the front element
    void addFront(const E& e); //add to front of the list
    void removeFront(); //remove front item list
    void print();
    private:
    SNode<E>* head; //head of the list
};

template <typename E>
SLinkedList<E>::SLinkedList(): head(NULL){

}

template <typename E>
bool SLinkedList<E>::empty() const{
    return head == NULL;
}

template <typename E>
const E& SLinkedList<E>::front() const{
    return head->elem;
}

template <typename E>
SLinkedList<E>::~SLinkedList(){
    while(!empty()){
        removeFront();
    }
}

template <typename E>
void SLinkedList<E>::addFront(const E& e){
    SNode<E>* v = new SNode<E>;
    v->elem = e;
    v->next = head;
    head = v;
}


template <typename E>
void SLinkedList<E>::removeFront(){
    SNode<E>* old = head;
    head = old->next;
    delete old;
}

//Print the list:
template <typename E>
void SLinkedList<E>::print(){
    //Create a reference to the head node of the list:
    SNode<E>* h = head;
    //If the list is empty - show a message:
    if(h == NULL){
        std::cout << "There are no elements in the linked-list. " << std::endl;
        return;
    }

    //Otherwise iterate through the list:
    while (h != NULL){
        std::cout << h->elem << std::endl;
        h = h->next;
    }
}

int main(){
    SLinkedList<int> a;
    a.addFront(350);
    a.addFront(23);
    a.addFront(34);
    a.addFront(512);

    //Print values:
    a.print();


    return 0;
}
