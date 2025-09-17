#include <iostream>
#include <vector>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> ans;
        TreeNode * curr = root;
        while (curr!= NULL){
            if (curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else {
                TreeNode * ip = curr->left;
                while (ip->right != NULL && ip->right != curr){
                    ip = ip->right;
                }
                if (ip->right == NULL){
                    ip->right = curr;
                    curr = curr->left;
                }
                else{
                    ip->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }            
        }
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
