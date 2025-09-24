#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



class Solution {
public:
    int Depth(TreeNode* root){
        if (!root) return 0;
        
        int left = Depth(root->left);
        if (left == -1) return -1;
        
        int right = Depth(root->right);
        if (right == -1) return -1;
        
        return abs(left - right) <= 1 ? 1 + max(left, right) : -1;
    }
    
    bool isBalanced(TreeNode* root) {
        return Depth(root) != -1;
    }
};

