#include <iostream>
using namespace std;

class Node{
public:
    Node* prev;
    Node* next;
    int data;
    Node(int val){
        prev = next = NULL;
        data =val;
    }
};

class DoublyLinkedList{
public:
    Node*head;
    DoublyLinkedList(){
        head = NULL;
    }

    void insertAtHead(int val){
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;

    }

    void insertAtTail(int val){
        Node* newNode = new Node(val);
        if (head == NULL){
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp->next!= NULL){
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    void popBack(){
        if (head == NULL) return;
        if (head->next == NULL){
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while(temp->next->next!= NULL){
            temp = temp->next;
        }

        Node* last = temp->next;
        temp->next = NULL;
        delete last;
    }

    void insertAtMid(int val){
        Node *newNode = new Node(val);
        if (head == NULL){
            head = newNode;
            return;
        }

        else if (head ->next == NULL){
            head->next = newNode;
            newNode->prev = head;
            return;
        }

        int count = 0;
        Node* temp = head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }

        count = count/2;
        temp = head;
        while(count != 1){
            temp = temp->next;
            count--;
        }

        Node* ne = temp->next;

        temp->next = newNode;
        newNode->prev = temp;

        if (ne!= NULL){
            ne->prev = newNode;
            newNode->next = ne;
        }
        



    }



    void display(){
        if (head == NULL) return;
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};


int main(){

    DoublyLinkedList ll;
    ll.insertAtHead(10);
    ll.insertAtHead(20);
    ll.insertAtMid(33);
    ll.insertAtTail(20);
    ll.insertAtHead(30);
    ll.insertAtMid(40);
    ll.display();
    ll.popBack();
    ll.insertAtMid(1);
    cout << endl;
    ll.display();

    return 0;

}