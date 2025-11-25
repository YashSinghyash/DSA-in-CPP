#include <iostream>
using namespace std;

class CircularQueue{
public:
    int *arr;
    int frontIdx;
    int rearIdx;
    int capacity;
    int currSize;

    CircularQueue(int cap = 10000){
        capacity = cap;
        arr = new int[capacity];
        frontIdx = 0;
        rearIdx = -1;
        currSize = 0;
    }

    void push(int x){
        if (currSize == capacity) return;

        rearIdx = (rearIdx+1)%capacity;
        arr[rearIdx] = x;
        currSize++;
    }

    void pop(){
        if(currSize == 0) return;

        frontIdx = (frontIdx+1)%capacity;
        currSize--;
    }
};


int main(){

    return 0;
}