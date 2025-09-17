#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue <pair<TreeNode* , unsigned long long int >> q;
        q.push({root, 0});
        int ans= 0;
        while (q.size()>0){
            unsigned long long int stIdx = q.front().second;
            unsigned long long int endIdx = q.back().second;
            ans = max(ans, (int)(endIdx-stIdx+1));
            long long int curr = q.size();
            for (int i = 0 ; i < curr ; i++){
                auto curr = q.front();
                q.pop();
                if (curr.first->left) {
                    q.push({curr.first->left , 2 * curr.second +1});
                }
                if (curr.first->right) {
                    q.push({curr.first->right , 2 * curr.second +2});
                }
            }
        }
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    Solution sol;
    cout << sol.widthOfBinaryTree(root) << endl;
    return 0;
}
