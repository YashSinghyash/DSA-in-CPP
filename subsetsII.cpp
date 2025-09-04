#include <iostream>
#include <vector>


using namespace std;


void subsets(vector <int> &nums,vector <int> &ans , int i , vector <vector<int>> allSubsets ){
    if (i == nums.size()){
        allSubsets.push_back(ans);
        return ;
        
    }
    ans.push_back(nums[i]);

    subsets(nums,ans,i+1,allSubsets);
    ans.pop_back();
    int idx = i+1;

    while (idx < nums.size() && nums[idx-1]==nums[idx]){
        idx++;
    }

    subsets(nums,ans,idx,allSubsets);
}
int main(){

    vector <int> nums = {1,2,2};
    sort(nums.begin(),nums.end());

    vector <vector<int>> allSubsets;
    vector <int> ans;

    subsets(nums,ans,0,allSubsets);

    


}