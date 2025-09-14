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

int countNodes(Node* root) {
        
        if (root == NULL) return 0;
        
        int left = countNodes(root-> left);
        int right = countNodes(root-> right);
        
        return left+right+1;
}



int main(){
    int arr[] = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node * root = buildTree(arr);
    int count = countNodes(root);
    cout << " count " << count;
 

}