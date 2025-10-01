#include <stack>
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    ListNode* helper(stack<int>& s1, stack<int>& s2, int carry) {
        if (s1.empty() && s2.empty()) {
            if (carry == 1) {
                ListNode* newNode = new ListNode(1);
                return newNode;
            } else
                return NULL;
        }

        if (s1.empty()) {
            int sum = s2.top() + carry;
            s2.pop();
            if (sum > 9) {
                sum = sum % 10;
                ListNode* newNode = new ListNode(sum);
                newNode->next = helper(s1, s2, 1);
                return newNode;
            }
            ListNode* newNode = new ListNode(sum);
            newNode->next = helper(s1, s2, 0);
            return newNode;
        }

        if (s2.empty()) {
            int sum = s1.top() + carry;
            s1.pop();
            if (sum > 9) {
                sum = sum % 10;
                ListNode* newNode = new ListNode(sum);
                newNode->next = helper(s1, s2, 1);
                return newNode;
            }
            ListNode* newNode = new ListNode(sum);
            newNode->next = helper(s1, s2, 0);
            return newNode;
        }

        int sum = s1.top() + s2.top() + carry;
        s1.pop();
        s2.pop();
        if (sum > 9) {
            sum = sum % 10;
            ListNode* newNode = new ListNode(sum);
            newNode->next = helper(s1, s2, 1);
            return newNode;
        }
        ListNode* newNode = new ListNode(sum);
        newNode->next = helper(s1, s2, 0);
        return newNode;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> list1;
        stack<int> list2;

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        while (temp1) {
            list1.push(temp1->val);
            temp1 = temp1->next;
        }
        while (temp2) {
            list2.push(temp2->val);
            temp2 = temp2->next;
        }

        ListNode*h1 =  helper(list1, list2, 0);
        return reverseList(h1);
    }
};