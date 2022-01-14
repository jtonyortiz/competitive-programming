
//
//Author: James Ortiz
//File: counter.cpp
//Description: An example of the implementation of a Class in Modern C++
//Compile: g++ -wall -std=c++11 counter.cpp -o counter
//

#include <iostream>
using namespace std;
class Counter{
    public:
    Counter();
    int getCount();
    void increaseBy(int x);
    private:
    int count;
};

Counter::Counter()
{
    count = 0;
}

int Counter::getCount(){
    return count;
}

void Counter::increaseBy(int x){
    count += x;
}

int main(void){

    Counter ctr;
    cout << ctr.getCount() << endl;
    ctr.increaseBy(3);
    cout << ctr.getCount() << endl;
    ctr.increaseBy(5);
    cout << ctr.getCount() << endl;

    return 0;

}
