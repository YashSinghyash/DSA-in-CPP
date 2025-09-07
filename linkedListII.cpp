#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool linkList = false;
        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                linkList = true;
                break;
            } 
        }
        if (!linkList){
            return nullptr;
        }
        slow = head;
        while (slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = head->next->next;

    Solution s;
    ListNode* cycleStart = s.detectCycle(head);
    if (cycleStart != nullptr) {
        cout << "Cycle starts at node with value: " << cycleStart->val << endl;
    } else {
        cout << "No cycle" << endl;
    }

    return 0;
}
