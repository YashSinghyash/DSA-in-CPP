#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> nums = {1,1,1,1,1,2,2,2};
    int si = nums.size();
    sort(nums.begin(),nums.end());
    int freq = 1;
    int ans = nums[0];
    for (int i = 1 ;i < si ; i++ ){
        if (nums[i]==nums[i-1]){
            freq++;
        }
        else {
            freq = 1;
        }
        if (freq > si/2){
            ans = nums[i];
            cout << ans;
            break;
        }
    }


}