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

static int idx = -1;
TreeNode* buildTree(int arr[]){
    idx++;
    if(arr[idx] == -1) return NULL;

    TreeNode* root = new TreeNode(arr[idx]);
    root->left = buildTree(arr);
    root->right = buildTree(arr);
    return root;
}

class Solution {
public:
    bool isIdentical(TreeNode* p , TreeNode *q){
        if (p == NULL || q == NULL) return p == q;

        bool leftSame = isIdentical(p->left, q->left);
        bool rightSame = isIdentical(p->right , q->right);

        return leftSame && rightSame && (p->val == q->val);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL || subRoot == NULL) {
            return root == subRoot ;
        }
        else if (root->val == subRoot-> val && isIdentical(root, subRoot)){
            return true;
        }

        return isSubtree(root->left,subRoot)||isSubtree(root->right, subRoot);
    }
};

int main() {
    int tree1[] = {3,4,1,-1,-1,2,-1,-1,5,-1,-1};
    int tree2[] = {4,1,-1,-1,2,-1,-1};

    idx = -1;
    TreeNode* root = buildTree(tree1);
    idx = -1;
    TreeNode* subRoot = buildTree(tree2);

    Solution sol;
    bool result = sol.isSubtree(root, subRoot);

    cout << result << endl;  // prints 1 if subtree, 0 if not
    return 0;
}
