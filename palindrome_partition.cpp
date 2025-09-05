#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPal(string part){
        string s2 = part;
        reverse(s2.begin(),s2.end());
        return s2 == part;
    }
    void getAllParts(string s,vector<string> &partition, vector<vector <string>> &ans){
        if (s.size()==0){
            ans.push_back(partition);
            return;
        }
        for (int i = 0 ; i < s.size(); i++){
            string part = s.substr(0,i+1);
            if (isPal(part)){
                partition.push_back(part);
                getAllParts(s.substr(i+1),partition,ans);
                partition.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector <string>> ans;
        vector<string> partition;
        getAllParts(s, partition, ans );
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "aab";
    vector<vector<string>> ans = sol.partition(s);

    cout << "Palindrome partitions:\n";
    for (auto &vec : ans) {
        cout << "[ ";
        for (auto &str : vec) {
            cout << str << " ";
        }
        cout << "]\n";
    }

    return 0;
}
