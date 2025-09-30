//x node to found , root = root , l = left , r= right , curr = current
#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* l;
    Node* r;

    Node(int v) {
        val = v;
        l = r = NULL;
    }
};

Node* inorderPre(Node* root, Node* x) {
    if (x->l != NULL) {
        Node* curr = x->l;
        while (curr->r != NULL) {
            curr = curr->r;
        }
        return curr;
    }

    Node* pre = NULL;
    Node* curr = root;

    while (curr != NULL) {
        if (x->val > curr->val) {
            pre = curr;
            curr = curr->r;
        } else if (x->val < curr->val) {
            curr = curr->l;
        } else {
            break;
        }
    }
    return pre;
}
