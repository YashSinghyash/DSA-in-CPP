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

Node* merge(Node* left , Node* right){
    if (!left) return right;
    if (!right) return left;

    if (left->data > right->data){
        right->next = merge(left , right->next);
        return right;
    }

    else{
        left->next = merge(left->next , right);
        return left;
    }
}

Node* middle(Node*head){
    if (head == NULL || head->next == NULL) return head;
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;

}

Node* mergeSort(Node* head){
    if (!head || !head->next){
        return head;
    }

    Node* mid = middle(head);
    Node* righthead = mid->next;
    mid->next = NULL;

    Node* l1= mergeSort(head);
    Node* l2 = mergeSort(righthead);

    return merge(l1 , l2);
}

