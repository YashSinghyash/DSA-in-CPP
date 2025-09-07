#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


int main(){
    int nums[] = {2,7,11,15};
    int target = 17;
    unordered_map <int, int> m;
    vector <int> ans;
    for (int i =0 ; i < sizeof(nums)/sizeof(nums[0]) ; i++){
        int first = nums[i];
        int sec = target - first;
        if (m.find(sec)!=m.end()){
            ans.push_back(i);
            ans.push_back(m[sec]);
            break;
        }

        m[first] = i;
    }
    for (int i = 0 ; i <ans.size() ; i ++){
        cout << ans[i] << " ";
    }

}