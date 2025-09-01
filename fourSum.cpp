#include <iostream>
#include <vector>
using namespace std;


int main(){
    vector <int> nums = {1,0,-1,0,-2,2};
    int tar = 2;
    vector <vector<int>> ans;
    sort (nums.begin(),nums.end());
    int n = nums.size();
    for (int i = 0 ; i < nums.size() ; i++){
        if (i > 0 && nums[i]==nums[i-1]) continue;
        for (int j = i + 1 ; j < nums.size();){
            int p = j + 1;
            int q = n - 1;

            while (p < q){
                long long sum =(long long) nums[i] +(long long) nums[j] +(long long) nums[p] +(long long) nums[q];
                if (sum < tar){
                    p++;
                }
                else if (sum > tar){
                    q--;
                } else {
                    ans.push_back({nums[i],nums[j],nums[q],nums[p]});
                    p++ ; q--;

                    while (p < q && nums[p] == nums[p-1])p++;
                }

            }

            j++;
            while (j<n && nums[j] == nums[j-1]) j++;
        }
    }
}