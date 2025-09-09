#include <iostream>
#include <vector>
using namespace std;
class Stack{
    vector <int> v;

    public:
    void push_back(int val){
        v.push_back(val);
    }

    void pop_back(){
        v.pop_back();
    }

    int top(){
        return v[v.size()-1];
    }

    bool empty(){
        return (v.size() == 0);
    }
};



int main(){
    Stack a;

    a.push_back(10);
    a.push_back(30);
    a.push_back(40);
    
    while (!a.empty()){
        cout << a.top() << " ";
        a.pop_back();
    }
    
    return 0;
}