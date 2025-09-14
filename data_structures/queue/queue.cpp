#include <iostream>

using namespace std;

class Node{
public :
int data;
Node* next;

Node(int val){
    data = val;
    next = NULL;
}
};

class Queue{
    Node *head;
    Node* tail;

public:
    Queue() {
        head = tail = NULL;

    }

    void push(int data){
        Node *newNode = new Node (data);

        if (head == NULL){
            head = tail = newNode;
        }

        else{
            tail -> next = newNode;
            tail = newNode;
        }
    }

    void pop(){

        if (head == NULL){
            return;
        }
        Node *temp = head;

        head = head->next;
        delete temp;
    }



    bool empty(){
        if (head == NULL){
            return true;;
        }
        return false;
    }

    int front(){
        if (head == NULL){
            return -1;
        }

        return head->data;
    }

};


int main(){
    Queue q;

    q.push(10);
    q.push(11);
    q.push(12);


    while (!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}