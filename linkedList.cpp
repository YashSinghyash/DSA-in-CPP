#include <iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{

    Node* head;
    Node* tail;

    public:
    List(){
        head = tail = NULL;

    }

    void push_front(int val){
        Node* newNode = new Node(val);

        if (head == NULL){
            head = tail = newNode;
            return ;
        } else {
            newNode -> next = head;
            head = newNode;
            return ;
        }
    }

    void pop_front(){
        if (head == NULL){
            return;
        }
        else {
            Node *temp = head;
            head = head-> next;
            temp->next = NULL;
            delete temp;

        }
    }

    void push_back(int val){
        Node * newNode = new Node(val);

        if (head==NULL){
            head = tail = newNode;
            return;
        } else{
            tail -> next = newNode;
            tail = newNode;

        }
    }

    void pop_back(){

        if (head == NULL) return;
        Node *temp = head;

        while(temp->next != tail){
            temp = temp->next;


        }

        temp->next = NULL;
        delete tail; //this delete memory where it point to in heap
        tail = temp;

    }
    void insert(int val , int pos){
        if (pos<0){
            return;
        }
        if (pos==0){
            push_front(val);return;
        }

        Node*temp = head;
        for (int i = 0; i < pos-1; i++){
            temp = temp->next;


        }

        Node *newNode = new Node(val);
        newNode ->next = temp->next;
        temp->next = newNode;
    }
    void print__ll(){
        Node *temp = head;
        while (temp != NULL){
            cout << temp->data << "->";
            temp = temp->next;

        }

        cout << "null" << endl;
    }

    int search(int key){
        Node * temp = head;
        int idx = 0;
        while (temp != NULL){
            if (temp->data == key){
                return idx;
            }

            temp = temp-> next;
            idx++;

        }

        return -1;

    }
};



int main(){
    List ll;
    ll.push_front(10);
    ll.push_front(20);

    ll.push_front(30);
    ll.push_back(3);
    ll.pop_front();
    ll.insert(43,2);
    ll.pop_back();
    ll.print__ll();
    cout <<ll.search(43);
        return 0;
}