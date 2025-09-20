#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int key) {
    if (root == NULL) return new Node(key);
    if (key < root->data) 
        root->left = insert(root->left, key);
    else 
        root->right = insert(root->right, key);
    return root;
}

void inorder(vector<int> &nums , Node* root){
    if (root== NULL) return;
    inorder(nums, root->left);
    nums.push_back(root->data);
    inorder(nums,root->right);
}

bool twoSumBST(Node* root, int target) {
    vector<int> nums;
    inorder(nums,root);
    int st = 0 ; int end = nums.size()-1;
    while (st < end){
        if ((nums[st]+nums[end])==target) return true;
        if ((nums[st]+nums[end])>target){
            end--;
        }
        else{
            st++;
        }
    }
    return false;
}

int main() {
    int values[] = {5, 3, 7, 2, 4, 6, 8};
    int n = sizeof(values) / sizeof(values[0]);
    Node* root = NULL;

    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    int testTargets[] = {9, 12, 20, 7};
    int t = sizeof(testTargets) / sizeof(testTargets[0]);

    for (int i = 0; i < t; i++) {
        cout << "Target: " << testTargets[i] 
             << " -> TwoSum Exists? " 
             << (twoSumBST(root, testTargets[i]) ? "Yes" : "No") 
             << endl;
    }

    return 0;
}
