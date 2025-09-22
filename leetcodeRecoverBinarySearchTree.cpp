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
    TreeNode* prev;
    TreeNode* fir;
    TreeNode* sec;

    void inorder(TreeNode* root){
        if (root == NULL) return;

        inorder(root->left);
        if (prev != NULL && prev->val > root->val){
            if(!fir) fir = prev;
            sec = root;
        }
        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        int temp;
        temp = fir->val;
        fir->val = sec->val;
        sec->val = temp;
    }
};

void printInorder(TreeNode* node) {
    if(!node) return;
    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    Solution s;
    s.recoverTree(root);

    printInorder(root);
    cout << endl;

    return 0;
}
