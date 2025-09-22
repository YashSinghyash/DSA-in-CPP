#include <iostream>
using namespace std;

class Node{
public:
    Node *next;
    int val;
    Node(int data){
        val = data;
        next = nullptr;
    }
};

class SinglyLinkedList{
public:
    Node* head;
    SinglyLinkedList(){
        head = nullptr;
    }

    void insertEnd(int val){
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        
        else{
            Node* temp = head;
            while (temp ->next != NULL){
                temp = temp->next;
            }

            temp->next = newNode;
            return;
        }
    }

    void insertBeg(int val){
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    void popback(){
        if (head == NULL) return;
        if (head ->next == NULL) 
        {   delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while(temp->next->next!=NULL){
            temp = temp->next;
        }
        Node * last = temp->next;
        temp->next = NULL;
        delete last;

    }
    void display(){
        if (head == NULL) return;
        Node* temp = head;
        while(temp != NULL){
            cout << temp->val << " ";
            temp = temp->next;
        }
    }

};

int main(){
    SinglyLinkedList sl;
    sl.insertBeg(30);
    sl.insertEnd(40);
    sl.insertEnd(50);
    sl.insertBeg(10);
    sl.display();
    sl.popback();
    cout << endl;
    sl.display();

}