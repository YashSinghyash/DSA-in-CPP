#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

static int idx = -1;
Node* buildTree(int arr[]){
    idx++;
    if(arr[idx] == -1) return NULL;

    Node * root = new Node(arr[idx]);
    root->left = buildTree(arr);
    root-> right = buildTree(arr);
    return root; 
}

int sumBT(Node* root) {

    if (root == NULL) return 0;

    int lsum = sumBT(root->left);
    int rsum = sumBT(root->right);

    return lsum + rsum + root->data;
        
}


int main(){

    int arr[] = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node * root = buildTree(arr);
    int sum = sumBT(root);
    cout << sum;

}