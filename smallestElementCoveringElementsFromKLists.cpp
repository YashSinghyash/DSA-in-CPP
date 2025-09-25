#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;


class Node{
    public:
    int data;
    int row;
    int col;
    Node(int d, int r , int c){
        data = d;
        row = r;
        col = c;
    }
};


class compare{
    public:
    bool operator()(Node* a, Node*b){
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;

        priority_queue<Node* , vector <Node*> ,compare> minheap;

        for (int i = 0 ; i < k ; i++){
            minheap.push(new Node(nums[i][0] , i , 0));
            mini = min(nums[i][0] , mini);
            maxi = max(nums[i][0] , maxi);
        }

        int st = mini , end = maxi;

        while (!minheap.empty()){
            Node* temp = minheap.top();
            minheap.pop();

            mini = temp->data;

            if (maxi-mini  < end - st){
                st = mini;
                end = maxi;


            }

            if (nums[temp->row].size() > temp->col + 1){
                minheap.push(new Node(nums[temp->row][temp->col +1], temp->row , temp->col+1));
                maxi = max(nums[temp->row][temp->col +1] , maxi);
            }

            else break;

        }

        vector <int> ans;
        ans.push_back(st);
        ans.push_back(end);

        return ans;

    }
};