#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head -> next == NULL){
            return head;
        } 
        ListNode* newhead = head->next;
        ListNode* first = head;
        ListNode* sec = first->next;
        ListNode *prev = NULL;

        while (first != NULL && sec!= NULL){
            ListNode *third = sec->next;
            sec->next = first;
            first->next = third;
            if (prev != NULL){
                prev->next = sec;
            }
            prev = first;
            first = prev->next;
            if(first!=NULL){
                sec = first->next;
            }
        }
        return newhead;
    }
};

void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->val;
        if (curr->next != nullptr) cout << " -> ";
        curr = curr->next;
    }
    cout << endl;
}

ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < size; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    ListNode* head = createList(arr, n);
    cout << "Original list: ";
    printList(head);

    Solution sol;
    ListNode* swapped = sol.swapPairs(head);

    cout << "Swapped pairs: ";
    printList(swapped);

    return 0;
}
