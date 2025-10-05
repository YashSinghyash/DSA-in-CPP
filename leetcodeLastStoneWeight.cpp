#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxheap;

        for (auto a : stones ){
            maxheap.push(a);
        }

        while (maxheap.size() > 1){
            int a = maxheap.top();
            maxheap.pop();
            int b = maxheap.top();
            maxheap.pop();

            if (a!=b){
                int c = a- b;
                maxheap.push(c);
            }
        }

        if (maxheap.empty()) return 0;
        else return maxheap.top();
    }
};