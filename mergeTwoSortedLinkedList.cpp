#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
        if(h1 == nullptr || h2 == nullptr){
            return h1 == nullptr ? h2 : h1;
        }
        if (h1->val <= h2->val){
            h1->next = mergeTwoLists(h1->next,h2);
            return h1;
        } else {
            h2->next = mergeTwoLists(h1,h2->next);
            return h2;
        }
    }
};

int main() {
    ListNode* h1 = new ListNode(1);
    h1->next = new ListNode(3);
    h1->next->next = new ListNode(5);

    ListNode* h2 = new ListNode(2);
    h2->next = new ListNode(4);
    h2->next->next = new ListNode(6);

    Solution s;
    ListNode* merged = s.mergeTwoLists(h1, h2);

    while (merged != nullptr) {
        cout << merged->val << " ";
        merged = merged->next;
    }

    return 0;
}
