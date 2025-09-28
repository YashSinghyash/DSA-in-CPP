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
    ListNode* solve (ListNode* l1, ListNode* l2 , int carry){
        if (l1 == NULL && l2 == NULL){
            if (carry == 0) return NULL;
            else return new ListNode(carry);
        }
        if (!l1){
            int n = l2->val + carry;
            if (n > 9){
                n = n % 10;
                carry = 1;
            }
            else carry = 0;
            ListNode* newNode = new ListNode(n);

            newNode->next = solve(l1, l2->next , carry);
            return newNode;
        }
        if (!l2){
            int n = l1->val + carry;
            if (n > 9){
                n = n % 10;
                carry = 1;
            } else carry = 0;
            ListNode* newNode = new ListNode(n);

            newNode->next = solve(l1->next, l2 , carry);
            return newNode;
        }

        int n = l1->val + l2->val + carry;
        if (n > 9){
                n = n % 10;
                carry = 1;
        } else carry = 0;
        ListNode* newNode = new ListNode(n);
        newNode->next = solve(l1->next , l2->next , carry);
        return newNode;

    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carr = 0;
        return solve(l1 , l2 , carr);
    }
};