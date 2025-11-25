#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class maxHeap{
public:
    vector<int>heap;

    void push(int x){
        heap.push_back(x);
        int i = heap.size()-1;
        while (i > 0){
            int parent = (i-1)/2;
            if (heap[parent] < heap[i]){
                swap(heap[parent],heap[i]);
                i = parent;
            } else break;
        }
    }
    void heapify(int i){
        int largest = i;
        int leftC = 2*i + 1;
        int rightC = 2*i+2;

        if(leftC < heap.size() && heap[leftC] > heap[largest] ){
            largest = leftC;
        }
        else if(rightC < heap.size() && heap[rightC] > heap[largest] ){
            largest = rightC;
        }

        if (largest != i){
            swap(heap[largest], heap[i]);
            heapify(largest);
        }
    }
    int pop(){

        if (heap.size() == 0) return -1;
        int top = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
        return top;
    }

    bool empty(){
        return (heap.size() == 0);
    }


};


int main(){
    maxHeap heap;
    heap.push(1);
    heap.push(5);
    heap.push(3);
    heap.push(4);
    
    while (!heap.empty()){
        int a = heap.pop();
        cout << a;
    }

    return 0;
}