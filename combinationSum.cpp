#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    set <vector<int>> s;
    void getAllComb(vector <int> &arr, int idx, int tar, vector<vector<int>> &ans,vector<int> &comb){
        if (idx == arr.size() || tar < 0){
            return;
        }

        if (tar == 0){
            if(s.find(comb) == s.end()){
                ans.push_back(comb);
                s.insert(comb);
            }
            return;
        }

        // Single Include 
        comb.push_back(arr[idx]);
        getAllComb(arr , idx+1, tar-arr[idx], ans, comb );
        //Multi
        getAllComb(arr , idx, tar-arr[idx], ans, comb );
        //BackTrackign
        comb.pop_back();
        getAllComb(arr , idx+1, tar, ans, comb );
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        vector<vector<int>> ans;
        vector<int> comb;
        getAllComb(arr, 0 , tar , ans, comb);
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> arr = {2, 3, 6, 7};
    int tar = 7;

    vector<vector<int>> ans = sol.combinationSum(arr, tar);

    cout << "Combinations:\n";
    for (auto &v : ans) {
        cout << "[ ";
        for (int x : v) cout << x << " ";
        cout << "]\n";
    }

    return 0;
}
