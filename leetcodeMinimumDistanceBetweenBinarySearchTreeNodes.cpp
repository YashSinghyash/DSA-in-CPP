#include <iostream>
#include <climits>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void inorder(int &ans, int &prev, TreeNode *root)
    {

        if (root == NULL)
            return;

        inorder(ans, prev, root->left);
        if (prev == -1)
            prev = root->val;

        else
        {
            ans = min(root->val - prev, ans);
            prev = root->val;
        }
        inorder(ans, prev, root->right);
    }
    int getMinimumDifference(TreeNode *root)
    {
        int ans = INT_MAX;
        int prev = -1;
        inorder(ans, prev, root);
        return ans;
    }
};