#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Compare{
public :
    bool operator()(ListNode* a , ListNode* b){
        return a->val > b->val;
    }
};


class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*> , Compare> minheap;
        int n = lists.size();

        if (n == 0 ) return NULL;

        for (int i = 0 ; i < n ; i ++){
            if (lists[i] != NULL){
                minheap.push(lists[i]);
            }
        }
        ListNode* head = NULL;
        ListNode* tail = NULL;

        while (!minheap.empty()){
            ListNode * temp = minheap.top();
            minheap.pop();
            if (temp ->next != NULL ){
                    minheap.push(temp->next);
            }

            if (head == NULL) {
                head = temp;
                tail = temp;
                
            }
            else {
                tail ->next = temp;
                tail = tail->next;

            }

        }
        return head;
    }
};