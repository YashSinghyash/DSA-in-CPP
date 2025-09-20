#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    int countNode(ListNode* head){
        int count = 0;
        ListNode* temp = head;
        while(temp!= NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    TreeNode* helper(ListNode* &head , int n){
        if (head == NULL || n <= 0 ) return NULL;
        TreeNode* left = helper(head , n/2);
        TreeNode* temp = new TreeNode(head->val);
        temp->left = left;
        head = head -> next;
        temp->right = helper(head, n-n/2-1);
        return temp;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int n = countNode(head);
        TreeNode* ans = helper(head, n);
        return ans;
    }
};

void printInorder(TreeNode* root) {
    if(!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    TreeNode* root = sol.sortedListToBST(head);

    cout << "Inorder traversal of BST: ";
    printInorder(root);
    cout << endl;

    return 0;
}
