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
TreeNode* buildTree(int arr[]) {
    idx++;
    if(arr[idx] == -1) return NULL;

    TreeNode * root = new TreeNode(arr[idx]);
    root->left = buildTree(arr);
    root->right = buildTree(arr);
    return root; 
}

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL) {
            return p == q;
        }

        bool isLeftSame = isSameTree(p->left, q-> left);
        bool isRightSame = isSameTree(p-> right , q-> right);

        return isLeftSame && isRightSame && (p->val == q->val);
    }
};

int main() {
    int tree1[] = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    int tree2[] = {1,2,-1,1,3,4,-1,-1,5,-1,-1};

    idx = -1;
    TreeNode *p = buildTree(tree1);
    idx = -1;
    TreeNode *q = buildTree(tree2);

    Solution sol;
    bool result = sol.isSameTree(p, q);

    cout << result << endl; // prints 0 if different, 1 if same
    return 0;
}
