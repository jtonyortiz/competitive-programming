//
//Author: James Ortiz
//File: circllist.cpp
//Description: C++ Implementation of a Cicular Linked List
//Compile: g++ -std=c++11 -Wall circllist.cpp -o cllist
//

#include <iostream>
#include <string>

using namespace std;

typedef string Elem;
class CNode{
    private:
    Elem elem;
    CNode* next;
    
    friend class CircleList;
};

class CircleList{
    public:
    CircleList();               //Consturctor
    ~CircleList();              //Destructor:
    bool empty() const;         //Check if list is empty
    const Elem& front() const;  //get element at cursor
    const Elem& back() const;   //get element following cursor
    void advance();             //Advance cursor
    void add(const Elem& e);    //add after cursor
    void remove();      //Remove node after cursor

    private:
    CNode* cursor;  //Cursor:
}; 


//Consturctor:
CircleList::CircleList():cursor(NULL){
}

//Destructor:
CircleList::~CircleList(){
    while(!empty()){
        remove();
    }
}

//Check if List is Empty:
bool CircleList::empty() const{
    return cursor == NULL;
}

//Element at Cursor:
const Elem& CircleList::back() const{
    return cursor->elem;
}

//Element following cursor:
const Elem& CircleList::front() const{
    return cursor->next->elem;
}

//Advance Cursor:
void CircleList::advance(){
    cursor = cursor->next;
}

//Add element after cursor:
void CircleList::add(const Elem& e){
    CNode* v = new CNode;
    v->elem = e;
    if(cursor == NULL){
        v->next = v;
        cursor = v;
    }else{
        v->next = cursor->next;
        cursor->next = v;
    }
}

//Remove node after cursor:
void CircleList::remove(){
    CNode * old = cursor->next; //the node being removed:
    if(old == cursor){
        //List is now empty:
        cursor = NULL;
    }else{
        //Link out the old node:
        cursor->next = old->next;
    }
    delete old; //Delete old node
}


int main(){
    CircleList playlist;        //[]
    playlist.add("Stayin Alive"); //[Stayin Alive*]
    playlist.add("Le Freak");      //[Le Freak, Stayin Alive*]
    playlist.add("Jive Talkin");   //[Kive Talkin, Le Frwak, Stayin Alive*]

    playlist.advance();     //[Le Frak, Stayin Alive, Jive Talkin*]
    playlist.advance();     //[Stayin Alive, Jive Talkin, Le Freak*]
    playlist.remove();      //[Jive Talkin, Le Freak*]
    playlist.add("Disco Inferno");  //[Disco Inferno, Jive Talkin, Le Freak*]
    return 0;
}

