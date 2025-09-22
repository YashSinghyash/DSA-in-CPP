#include <iostream>

using namespace std;

class Node{
public:
    Node* next;
    int data;
    Node(int val){
        next = NULL;
        data =val;
    }
};


class Circular{
public:
    Node* head;
    Circular(){
        head = NULL;
    }

    void insertAtHead(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;
        while(temp->next!=head){
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
        head = newNode;

    }

    void insertAtBack(int val){
        Node* newNode = new Node(val);
        if (head == NULL){
            head = newNode;
            head->next = newNode;
            return;
        }

        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
        return;





    }

    void popAtBack(){
        if (head == NULL) return;
        if (head ->next == head) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while(temp->next->next!=head){
            temp = temp->next;
        }
        Node* last = temp->next;
        temp->next = head;
        delete last;



    }

    void display(){
        if (head == NULL) return;
        Node* temp = head->next;
        cout << head->data << " ";
        while(temp != head){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

};

int main(){
    Circular cl;
    cl.insertAtHead(10);
    cl.insertAtHead(20);
    cl.insertAtBack(13);
    cl.insertAtHead(11);
    cl.popAtBack();
    cl.display();
    cl.insertAtHead(19);
    cl.popAtBack();
    cout<<endl;
    cl.display();

    return 0;
}


