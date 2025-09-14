#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node * left;
    Node * right;
    Node (int val){
        data = val;
        left=right=NULL;
    }
};
static int idx = -1;
Node *getRoot(int arr[]){
    idx++;
    
    if (arr[idx] == -1){ return NULL;}
    Node * root = new Node(arr[idx]);
    root -> left = getRoot(arr);
    root -> right = getRoot(arr);
    return root;
}

void preorder(Node * root){
     if ( root == NULL) return;
     cout << root->data << " ";
     preorder (root->left);
     preorder(root->right);
}

void inorder(Node * root){
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);

}

void postorder(Node * root){
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";


}

void levelorder(Node *root){
    queue <Node *> q;
    q.push(root);
    q.push(NULL);

    while (q.size() > 0){
        Node *curr = q.front();
        q.pop();

        if (curr == NULL){
            if(q.empty()){
                break;
            }
            else{

                cout << endl;
                q.push(NULL);
                continue;
            }
        }

        cout << curr->data<<" ";

        if (curr->left != NULL) q.push(curr->left);
        if (curr->right != NULL) q.push(curr->right);


    }
}



int main(){
    int arr[11] = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node * root = getRoot(arr);

    preorder(root); 
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    levelorder(root);

}