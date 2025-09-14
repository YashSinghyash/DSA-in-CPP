#include <iostream>
using namespace std;


class CircularQueue{

    int * arr;
    int currSize;
    int cap ; 
    int r,f;

public:
    CircularQueue(int size){
        cap = size;
        r = -1;
        f = 0;
        currSize = 0;
        arr = new int[size];
    }

    void push(int val){
        if (currSize == cap){   
            cout << "Queue is full" << endl;
        return ;
        } 
        r = (r+1)%cap;
        arr[r] = val;
        currSize++;
    }

    void pop(){
        if (empty()) return;
        f = (f+1)%cap;
        currSize--;
    }

    int front(){

        if (empty()){
            return -1;
        }

        return arr[f];

    }

    bool empty(){
        return currSize == 0;
    }

    void printArr(){
        for (int i = 0 ; i < cap ; i++){
            cout << arr[i] <<" ";
            
        }
        cout << endl;
    }

};


int main(){

    CircularQueue cq(3);

    cq.push(3);
    cq.push(2);
    cq.push(4);
    cq.push(5);
    cq.pop();
    // cq.push(1);
    cq.printArr();
    while (!cq.empty()){
        cout << cq.front() << " ";
        cq.pop();
    }

    return 0;
}