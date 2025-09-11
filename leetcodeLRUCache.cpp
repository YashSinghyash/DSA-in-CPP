#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    class Node {
        public :
            int key;
            int val;
            Node *prev;
            Node *next;

            Node (int k , int v){
                key = k;
                val = v;
                prev = next = NULL;
            }
    };

    Node *head = new Node(-1,-1);
    Node *tail = new Node (-1,-1);
    unordered_map <int ,  Node*> m;
    int limit;

    void addNode(Node* newNode){
        Node *oldNext = head->next;
        oldNext-> prev = newNode;
        head->next = newNode;
        newNode->next = oldNext;
        newNode -> prev = head;
    }

    void deleteNode(Node* node){
        Node *oldprev = node->prev;
        Node *oldnext = node->next;
        oldprev ->next = oldnext;
        oldnext ->prev = oldprev;
    }

    LRUCache(int capacity) {
        limit = capacity;
        head -> next = tail;
        tail ->prev = head;
    }

    int get(int key) {
        if (m.find(key) == m.end()){
            return -1;
        }
        int ans = m[key]->val;
        Node * ansNode = m[key];
        deleteNode(ansNode);
        addNode(ansNode);
        return ans;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()){
            Node * oldNode = m[key];
            deleteNode(oldNode);
            m.erase(key);
        }
        if (m.size()==limit){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node *newNode = new Node(key , value);
        addNode(newNode);
        m[key] = newNode;
    }
};

int main() {
    LRUCache cache(2);

    cache.put(1, 10);
    cache.put(2, 20);

    cout << cache.get(1) << endl;

    cache.put(3, 30);

    cout << cache.get(2) << endl;
    cout << cache.get(3) << endl;

    cache.put(4, 40);

    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;

    return 0;
}
