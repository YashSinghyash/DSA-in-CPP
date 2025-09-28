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
    int CountNode(ListNode* head){
        if (head == NULL) return 0;
        ListNode* temp = head;

        int count = 0;
        while (temp != NULL){
            count++;
            temp = temp->next;
        }

        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = CountNode(head);
        int index = count -n;
        if (count == n){
            head = head->next;
            return head;
        }

        ListNode* prev = NULL;
        ListNode* temp = head;

        while (index != 0){
            prev = temp;
            temp = temp->next;
            index--;
        }

        prev->next = temp->next;
        delete temp;

        return head;

    }
};