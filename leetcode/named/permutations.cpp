#include <iostream>
using namespace std;

void permutation(vector <int> &nums, int idx , vector <vector<int>> &ans){
    if (nums.size() == idx){
        ans.push_back({nums});
        return;
    }
    for (int i = idx ; i < nums.size() ; i++){
        swap(nums[idx],nums[i]);

        permutation(nums,idx+1, ans);
        swap(nums[i],nums[idx]);

    }
}

int main{



    return 0;
}