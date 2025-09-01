#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    int n = nums.size();
    
    set <vector <int>> untrip;
    set <vector<int>> trip;

    for(int i =0 ; i<n ; i++ ){
        int tar = -nums[i];
        set <int> s;
        for (int j = i + 1 ; j < n ; j++){
            int third = tar - nums[j];
            if (s.find(third)!= s.end()){
                vector<int> trip = {nums[i],nums[j],third};
                sort(trip.begin(),trip.end());
                untrip.insert(trip);
            }

            s.insert(nums[j]);
        }
    }

    vector <vector<int>> ans (untrip.begin(),untrip.end());

    for (vector<int> &vec : ans){
    for (int x : vec){
        cout << x << " ";
    }
    cout << endl;
}


}