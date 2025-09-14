#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        unordered_map <Node*,Node*>m;
        Node* newTemp = new Node(head->val);
        Node* oldTemp = head;
        oldTemp = oldTemp->next;
        Node* newHead = newTemp;
        m[head] = newHead;

        while (oldTemp!=NULL){
            Node* copyTemp = new Node(oldTemp->val);
            newTemp -> next = copyTemp;
            m[oldTemp] = copyTemp;
            oldTemp = oldTemp ->next;
            newTemp = newTemp-> next;
        }

        oldTemp = head;
        newTemp = newHead;

        while (oldTemp != NULL){
            newTemp->random = m[oldTemp->random];
            newTemp = newTemp->next;
            oldTemp = oldTemp->next;
        }

        return newHead;
    }
};

int main() {
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);

    a->next = b;
    b->next = c;

    a->random = c;
    b->random = a;
    c->random = b;

    Solution s;
    Node* copiedHead = s.copyRandomList(a);

    Node* temp = copiedHead;
    while (temp != NULL) {
        cout << "Node val: " << temp->val << ", ";
        if (temp->random) cout << "Random val: " << temp->random->val;
        else cout << "Random val: NULL";
        cout << endl;
        temp = temp->next;
    }

    return 0;
}
