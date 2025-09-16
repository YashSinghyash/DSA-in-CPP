#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* buildTree(int preorder[], int& index, int n) {
    if(index >= n || preorder[index] == -1) {
        index++;
        return NULL;
    }
    Node* root = new Node(preorder[index++]);
    root->left = buildTree(preorder, index, n);
    root->right = buildTree(preorder, index, n);
    return root;
}

void printTree(Node* root) {
    if(root == NULL) return;
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

int sumTree(Node* root){
    if (root == NULL) return 0;

    int leftSum = sumTree(root->left);
    int rightSum = sumTree(root->right);

    root->data += leftSum+rightSum;
    return root->data;

}


int main() {
    int preorder[] = {1, 2, -1,-1,3,4,-1,-1,5,-1,-1};
    int n = sizeof(preorder)/sizeof(preorder[0]);
    int index = 0;
    Node* root = buildTree(preorder, index, n);

    printTree(root);
    int a = sumTree(root);
    cout << endl;
    printTree(root);
    return 0;
}
