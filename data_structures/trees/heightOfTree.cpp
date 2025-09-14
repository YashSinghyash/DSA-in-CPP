#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int height(Node* node) {
    if (node == NULL) return 0;

    int lht = height(node->left);
    int rht = height(node->right);

    return max(lht, rht) + 1;
}

int main() {
    Node* root = new Node(12);
    root->left = new Node(8);
    root->right = new Node(18);
    root->left->left = new Node(5);
    root->left->right = new Node(11);

    cout << "Height: " << height(root) << endl;

    return 0;
}
