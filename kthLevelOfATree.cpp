#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void kthLevel(Node * root , int k){

    if (root == NULL) return;

    if (k==1){cout << root-> data << " ";
        return;

    } 
    
    kthLevel(root->left , k-1);
    kthLevel(root->right , k-1);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->right->left = new Node(4);
    root->right->right = new Node (5);
    kthLevel(root , 3);
    return 0;
}