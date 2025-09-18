#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node * right;
    Node * left;

    Node(int d){
        data = d;
        left = right = NULL;
    }
};

Node* insertData(Node* root , int data){
    if (root == NULL){
        root = new Node(data);
        return root;
    }

    if ( data > root->data){
        root->right = insertData(root->right,data);
    }
    else {
        root->left = insertData(root->left,data);
    }

    return root;
}

void takeInput(Node* &root){
    int data;
    cin >> data;

    while (data!=-1){
        root = insertData(root, data);
        cin >> data;
        
    }

}

bool search(Node* root, int x) {

    
    if (root == NULL) return false;
    
    if (root->data == x) return true;
    
    if (root->data > x){
        return search (root->left , x);
    }
    
    else {
        return search (root->right , x);
    }
}

int main(){
    Node * root = NULL;

    cout << "Enter " << endl;
    takeInput(root);

    bool ans = search(root, 15);
    cout << ans;
    return 0;
}