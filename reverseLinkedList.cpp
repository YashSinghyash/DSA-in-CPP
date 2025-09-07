#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * prev = NULL;
        ListNode * curr = head;
        ListNode * next = NULL;

        while (curr != NULL){
            next = curr-> next;
            curr-> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    Solution s;
    ListNode* rev = s.reverseList(head);

    while (rev != NULL) {
        cout << rev->val << " ";
        rev = rev->next;
    }
    return 0;
}
