#include <iostream>
#include <stack>
using namespace std;


struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
    stack <TreeNode*> s;

    void pushnodesleft(TreeNode* root){
        if (root == NULL) return;
        s.push(root);
        pushnodesleft(root->left);
    }

    BSTIterator(TreeNode* root) {
        pushnodesleft(root);
    }
    
    int next() {
        TreeNode* ans = s.top();
        s.pop();
        pushnodesleft(ans->right);
        return ans->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};