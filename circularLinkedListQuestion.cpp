#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularList {
public:
    Node* head;
    CircularList() {
        head = nullptr;
    }

    void insertAtStart(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            newNode->next = newNode;
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            newNode->next = newNode;
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    void insertAtMid(int val, int pos) {
        Node* newNode = new Node(val);
        if (!head) {
            newNode->next = newNode;
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos && temp->next != head; i++)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtStart() {
        if (!head) return;
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        Node* last = head;
        while (last->next != head)
            last = last->next;
        head = head->next;
        last->next = head;
        delete temp;
    }

    void deleteAtEnd() {
        if (!head) return;
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        delete temp;
    }

    void deleteAtMid(int pos) {
        if (!head) return;
        if (pos == 1) {
            deleteAtStart();
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        for (int i = 1; i < pos && temp->next != head; i++) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == head) return;
        prev->next = temp->next;
        delete temp;
    }

    void printList() {
        if (!head) return;
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularList cll;
    cll.insertAtStart(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.insertAtMid(15, 2);
    cll.printList();
    cll.deleteAtStart();
    cll.printList();
    cll.deleteAtEnd();
    cll.printList();
    cll.deleteAtMid(2);
    cll.printList();
    return 0;
}
