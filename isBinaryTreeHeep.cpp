#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    int countNode(Node* tree){
        if (tree == NULL) return 0;
        int ans = 1 + countNode(tree->left) + countNode(tree->right);
        return ans;
    }
    
    bool isCbt(Node* tree , int i , int nodes){
        if (tree == NULL) return true;
        if (i >= nodes) return false;
        else {
            return isCbt(tree->left, (2*i)+1, nodes) && 
                   isCbt(tree->right, (2*i)+2, nodes);
        }
    }
    
    bool isMax(Node * tree){
        if (tree == NULL) return true;
        if (tree->left == NULL && tree->right == NULL) return true;
        if (!tree->right){
            return tree->data >= tree->left->data;
        } 
        else {
            return tree->data > tree->left->data && tree->data > tree->right->data && 
                   isMax(tree->left) && isMax(tree->right);
        }
    }
    
    bool solve(Node* tree, int i, int nodes){
        return isCbt(tree, i, nodes) && isMax(tree);
    }

    bool isHeap(Node* tree) {
        int nodes = countNode(tree);
        return solve(tree, 0, nodes);
    }
};

int main() {
    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);

    Solution sol;
    if (sol.isHeap(root))
        cout << "The tree is a Heap" << endl;
    else
        cout << "The tree is not a Heap" << endl;

    return 0;
}
