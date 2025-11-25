#include <iostream>
using namespace std;


class Node{
public:
    int key;
    Node* left;
    Node* right;

    int height;

    Node(int val){
        key =val;
        left = right = nullptr;
        height = 1;
    }
};

int height(Node* root){
    if (root == NULL) return 0;
    else return root->height;
}

int balance(Node* root){
    if (root==NULL) return 0;
    else return height(root->left)-height(root->right);
}

Node* rightRotate(Node*root){
    Node* x = root->left;
    Node* y = x->right;

    x->right = root;
    root->left = y;

    x->height = 1 + max(height(x->left), height(x->right));
    root->height = 1 + max(height(root->left),height(root->right));

    return x;
}

Node* rightRotate(Node* root){


}

Node* insertNode(Node* root , int key){
    Node* newNode = new Node(key);
    if (root == NULL) return newNode;

    if (root->key > key){
        root->left = insertNode(root->left,key);
    }
    else if (root->key < key){
        root->right = insertNode(root->right , key);
    }
    else{
        return root;
        
    }

    root->height = 1+ max(height(root->left),height(root->right));

    int bf = balance(root);

    if (bf > 1 && key< root->left->key ){
        return rightRotate(root);
    }

    if (bf > 1 && key > root->left->key){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

}

int main(){


}