#include <iostream>
#include <set>
#include <vector>


using namespace std;

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector <vector<int>> ans;
    sort(nums.begin(),nums.end());
    for (int i = 0 ; i < nums.size() ; i++){
        if (i > 0 && nums[i] == nums[i-1]) continue;
        int j = i + 1 ; 
        int k = nums.size()-1;

        while (j < k){
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0 ){
                j++ ;
            }

            else if (sum > 0){
                k--;
            } else {
                ans.push_back({nums[i],nums[j],nums[k]});
                j++ , k--;

                while (j<k && nums[j]==nums[j-1]) j++;
            }

        }
    }


    
}