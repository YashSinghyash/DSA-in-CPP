#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    void inorder(vector<Node*> &nums , Node* root){
        if (root== NULL) return;
        inorder(nums, root->left);
        nums.push_back(root);
        inorder(nums,root->right);
    }

    Node* helper(vector<Node*> &nums , int st , int end){
        if (st > end) return NULL;
        int mid = st + (end-st)/2;
        Node* root = nums[mid];
        root->left = helper(nums,st,mid-1);
        root->right= helper(nums,mid+1,end);
        return root;
    }

    Node* balanceBST(Node* root) {
        vector <Node*> nums;
        inorder(nums,root);
        Node* mroot = helper(nums,0,nums.size()-1);
        return mroot;
    }
};

void inorderPrint(Node* root) {
    if(!root) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main() {
    Node* root = new Node(1);
    root->right = new Node(2);
    root->right->right = new Node(3);
    root->right->right->right = new Node(4);

    Solution sol;
    Node* balancedRoot = sol.balanceBST(root);
    inorderPrint(balancedRoot);
    cout << endl;

    return 0;
}
