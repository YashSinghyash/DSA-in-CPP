#include <iostream>

using namespace std;

struct Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

struct Singly
{
public:
    Node *head;
    Singly()
    {
        head = NULL;
    }

    void insertNodeAtBeg(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    void insertNodeAtEnd(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void traversal()
    {
        if (head == NULL)
        {
            return;
        }

        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data;
            if (temp->next != NULL)
            {
                cout << "->";
            }
            temp = temp->next;
        }

        cout << endl;
    }

    void SearchElement(int val)
    {
        if (head == NULL)
        {
            cout << "Empty List ";
            return;
        }
        Node *temp = head;

        int pos = 0;
        while (temp != NULL)
        {
            if (temp->data == val)
            {
                cout << "Position (0 based indexing): " << pos;
                return;
            }

            temp = temp->next;
            pos++;
        }

        cout << "Not Found";
    }

    void deleteVal(int val)
    {
        if (head == NULL)
        {
            cout << "Empty List";
            return;
        }

        Node *temp = head;
        if (head->data == val)
        {
            head = head->next;
            delete temp;
            return;
        }
        while (temp != NULL && temp->next != NULL)
        {

            if (temp->next->data == val)
            {
                Node *todelete = temp->next;
                temp->next = temp->next->next;
                delete todelete;
                return;
            }
            temp = temp->next;
        }

        cout << "Element Not Found";
    }
};
class Circular
{
public:
    Node *head;
    Circular()
    {
        head = NULL;
    }

    void insertNodeAtHead(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
        head = newNode;
        return;
    }

    void insertNodeAtTail(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
            newNode->next = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
        return;
    }

    void traversal()
    {
        if (head == NULL)
        {
            cout << "Empty Linked List" << endl;
            return;
        }

        Node *temp = head->next;
        cout << head->data << "->";
        while (temp != head)
        {
            cout << temp->data ;
            if (temp->next!= head){
                cout << "->";
            }
            temp = temp->next;
        }

        cout << endl;
    }

    // same for search logic
    void deleteFromList(int val){
        if (head == NULL){
            cout << "List is empty";
            return;
        }

        if (head->data == val){
            //only head

            if (head->next == head){
                delete head;
                head = NULL;
                return;
            }
            //more nodes

            Node* last = head;
            while(last->next!= head){
                last = last->next;
            }

            Node* todelete = head;
            last->next = head->next;
            head = head->next;
            delete todelete;
            return;
        }


        Node* prev = head;
        Node* curr = head->next;

        while(curr != head){
            if (curr->data == val){
                prev->next = curr->next;
                delete curr;
                return;
            }

            prev = curr;
            curr = curr->next;
        }


        cout << "Can not find" << endl;

    }
};


class Stack{
private:
    int* arr;
    int capacity;
    int topindex;

public:
    Stack(int size){
        capacity = size;
        arr = new int[capacity];
        topindex = -1;
    }

    void top(){
        if (isempty()){
            cout << "Empty" <<endl;
            return;
        }

        cout << arr[topindex];
        return;
    }
    void push(int val){
        if (topindex+1 == capacity){
            cout << "Stack overflow" << endl;
            return;
        }

        topindex++;
        arr[topindex] = val;
        return;
    }

    void pop(){

        if (topindex == -1){
            cout << "Stack Underflow" <<endl;
            return;
        }

        topindex--;
        return;
    }
    bool isempty(){
        return topindex==-1;
    }
    void display(){
        if (topindex == -1){
            cout << "Stack is empty" <<endl ;
            return;
        }

        for (int i = topindex ; i > -1 ;i--){
            cout << arr[i] <<" ";
        }

        return;
    }


};


int main()
{
    // Singly s;
    // s.insertNodeAtBeg(10);
    // s.insertNodeAtBeg(20);
    // s.insertNodeAtEnd(11);
    // s.insertNodeAtBeg(1);
    // s.traversal();
    // s.SearchElement(11);

    // Circular c;
    // c.insertNodeAtHead(10);
    // c.insertNodeAtHead(20);
    // c.insertNodeAtTail(30);
    // c.insertNodeAtTail(1);
    // c.insertNodeAtTail(3);
    // c.traversal();
    // c.deleteFromList(4);
    // c.deleteFromList(1);
    // c.deleteFromList(20);
    // c.traversal();

    Stack st(100);

    st.push(10);
    st.push(11);
    st.push(12);
    st.display();
    st.top();
    st.pop();
    st.top();

}

