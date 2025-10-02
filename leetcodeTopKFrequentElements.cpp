#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> map;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        for (int i = 0 ; i < nums.size() ; i++){
            if (map.find(nums[i]) == map.end()){
                map[nums[i]] = 1;
            }

            else map[nums[i]]++;

        }

        for (auto &m : map){
            minHeap.push({m.second,m.first});
            if (minHeap.size() > k ){
                minHeap.pop();
            }
        }

        vector <int> ans;

        while (!minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }


        return ans;
    }
};