#include <iostream>
#include <vector>
#include <queue>
#include <map>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


using namespace std;
vector<int> topView(Node *root) {
    vector <int> ans;
    queue <pair<Node* , int>> q;
    map <int , int> m;
    
    q.push({root,0});
    
    while (!q.empty()){
        Node * curr = q.front().first;
        int hd = q.front().second;
        q.pop();
        
        if (m.find(hd) == m.end()){
            m[hd] = curr->data;
        }
        
        if (curr->left != NULL){
            q.push({curr->left , hd-1});
        }
        
        if (curr->right != NULL){
            q.push({curr->right , hd+1});
        }
    }
    
    for (auto it : m){
        ans.push_back(it.second);
    }
    
    return ans;
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);

    vector<int> result = topView(root);

    cout << "Top view: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}