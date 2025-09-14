#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int c= 0;

        while (c < k) {
            if (temp == NULL){
                return head;
            }
            temp = temp->next;
            c++;
        }

        ListNode *prev = reverseKGroup(temp , k);

        temp = head;
        c = 0;

        while (c < k){
            ListNode *next = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = next;
            c++;
        }

        return prev;
    }
};

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

ListNode* createList(int arr[], int size) {
    if (size == 0) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    Solution sol;
    int arr[] = {4, 2, 1, 4, 5};
    int k = 2;
    int size = sizeof(arr) / sizeof(arr[0]);
    ListNode* head = createList(arr, size);
    printList(head);
    ListNode* result = sol.reverseKGroup(head, k);
    printList(result);
    return 0;
}
