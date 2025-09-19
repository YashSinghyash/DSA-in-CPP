#include <iostream>
#include <queue>
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

Node* minVal(Node * root){
    if (root== NULL) return NULL;
    Node* temp = root;
    while (temp->left != NULL){
        temp = temp->left;
    }

    return temp;
}

Node * deleteNodeBST(Node *root , int val){
    if (root == NULL) return NULL;
    if (root->data == val){
        if (root->right == NULL && root->left == NULL){
            delete root;
            return NULL;
        }

        if (root->right == NULL && root->left != NULL){
            Node * temp = root;
            temp = root->left;
            delete root;
            return temp;
        }
        //right child
        if (root->right != NULL && root->left == NULL){
            Node * temp = root;
            temp = root->right;
            delete root;
            return temp;
        }
        //2 child

        if (root->right != NULL && root->left != NULL){
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteNodeBST(root->right,mini);
            return root;
        }
    }   

    if (root->data > val){
        root->left = deleteNodeBST(root->left,val);
    }

    else{
        root->right = deleteNodeBST(root->right,val);
    }
    return root;
}

int main(){
    Node* root = NULL;
    cout << "Enter";
    takeInput(root);
    levelorder(root);
    root = deleteNodeBST(root,15);
    cout << endl;
    levelorder(root);
}