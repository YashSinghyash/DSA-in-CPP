#include <iostream>
#include <vector>
#include <list>


using namespace std;

class Stack{
list<int>ll;
public:
    void push_back(int val){
        ll.push_front(val);
    }
    int top(){
        return ll.front();
    }
    void pop(){
        ll.pop_front();
    }
    bool empty(){
        return ll.size() == 0;
    }
};

int main(){
    Stack a;

    a.push_back(10);
    a.push_back(30);
    a.push_back(40);
    
    while (!a.empty()){
        cout << a.top() << " ";
        a.pop();
    }
    
    return 0;
}