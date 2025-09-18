#include <iostream>

using namespace std;


class Node{
public:
    int data;
    Node * left;
    Node * right;
Node (int d) {
    data = d;
    left = right = NULL;
}
};

void takeInput(Node* root){
    int data;
    cin >> data;

    while (data!=-1){
        root = insertData(root, data);
        cin >> data;
        
    }

}

int main(){
    Node * root = NULL;

    cout << "Enter " << endl;
    takeInput(root);

    return 0;
}