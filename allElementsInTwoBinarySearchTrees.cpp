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
    void inorder(TreeNode* root , vector<int> &arr){
        if (root == NULL) return;

        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
        return;
        

        
    }

    vector<int> merge(vector<int> arr1, vector<int> arr2 ){
        if (arr1.size()==0) return arr2;
        if (arr2.size()==0) return arr1;
        vector<int> ans(arr1.size()+arr2.size());

        int i = 0 , j = 0 , k = 0;

        while (i < arr1.size() && j < arr2.size() ){
            if (arr1[i] > arr2[j]) {
                ans[k++] = arr2[j++];
            }
            else{
                ans[k++] = arr1[i++];
            }
        }

        while (i <arr1.size()){
            ans[k++] = arr1[i++];
        }
        while (j <arr2.size()){
            ans[k++] = arr2[j++];
        }

        return ans;

    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1;
        vector<int> arr2;
        inorder(root1,arr1);
        inorder(root2 , arr2); 

        vector<int> ans = merge(arr1,arr2);
        return ans;


    }
};