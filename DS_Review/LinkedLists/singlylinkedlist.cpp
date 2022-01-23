//
//Author: James Anthony Ortiz
//File: singlylinkedlist.cpp
//Description: Implementation of a singly-linkied list in C++
//

#include <string>
#include <iostream>
using namespace std;


class StringNode {
    private:
    std::string elem;
    StringNode* next;

    friend class StringLinkedList;
};

class StringLinkedList{
public:
StringLinkedList();  //Constructor:
~StringLinkedList(); //destructor:
bool empty() const; //Chck if the Linked-List is empty
const string& front() const; //Get front element
void addFront(const string& e); //add a node to the front
void removeFront(); //remove a node from the front

private:
StringNode* head;

};

//Constructor:
StringLinkedList::StringLinkedList(): head(nullptr){

}

//Desctructor:
StringLinkedList::~StringLinkedList(){
    while(!empty()){
        removeFront();
    }
}

//Check if the list is empty:
bool StringLinkedList::empty() const{
    return head == nullptr;
}

//Obtain the front element:
const string& StringLinkedList::front() const{
    return head->elem;
}


//Add to the front of the list:
void StringLinkedList::addFront(const string& e){
    StringNode* v = new StringNode; //Create a new node:
    v->elem = e; //Assign element to parameter
    v->next = head; //Set the next pointer to the head
    head = v; //Assign the old head to the new head node
}


//Remove the front item
void StringLinkedList::removeFront(){
    StringNode* old = head; //save the current head
    head = old->next; //Skip over the old head
    delete old; //Delete the old head
}

