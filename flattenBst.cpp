#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
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
    Node *flattenBST(Node *root) {
        vector<Node*> nums;
        inorder(nums,root);
        for (int i = 0 ; i <nums.size()-1;i++){
            nums[i]->right = nums[i+1];
            nums[i]->left = NULL;
        }

        nums[nums.size()-1]->right = NULL;
        nums[nums.size()-1]->left = NULL;
        return nums[0];
    }
};

void printRight(Node* root) {
    while(root) {
        cout << root->data << " ";
        root = root->right;
    }
    cout << endl;
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    Solution sol;
    Node* head = sol.flattenBST(root);
    printRight(head);

    return 0;
}
