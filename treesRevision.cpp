#include <iostream>
using namespace std;

struct Node{
public:
    int data;
    Node * left;
    Node * right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;
Node* buildTree(int pro[]){
    idx++;
    if (pro[idx] == -1) return NULL;

    Node * root = new Node (pro[idx]);
    root->left = buildTree(pro);
    root->right = buildTree(pro);
    return root;
}

void printTree(Node * root){
    if (!root) {
        cout << -1 << " " ;
        return;
    }
    cout << root->data <<" ";

    printTree(root->left);
    printTree(root->right);
}

void preOrder(Node* root){
    if (root == NULL) return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

bool isSame (Node*p , Node*q){
    if (p==NULL || q == NULL) {
        return p == q;
    }

    bool isLeft = isSame(p->left , q->left);
    bool isRight = isSame(p->right, q->right);


    return (isLeft && isRight && (p->data==q->data));
}


bool isSubTree(Node * r , Node * sr){
    if (r == NULL || sr == NULL){
        return (r == sr);
    }

    
}


int main(){
    int pro[] = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(pro);
    printTree(root);
}
