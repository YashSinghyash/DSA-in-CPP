#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        stack <int> s;
    
    for (int i = 0 ; i < n ; i++){
        s.push(i);
    }
    
    while (s.size()>1){
        int i = s.top();
        s.pop();
        int j = s.top();
        s.pop();
        
        if (mat[i][j] == 0){
            s.push(i);
        } else s.push(j);
        
        
        
    }
    
    int celeb = s.top();
    
    for (int i = 0 ; i < n ; i++){
        if (i!=celeb &&( mat[i][celeb] == 0 || mat[celeb][i] == 1)){
            return -1;
        }
    }
    
    
    return celeb;
    }
};

int main() {
    vector<vector<int>> mat = {
        {0,1,1},
        {0,0,1},
        {0,0,0}
    };
    Solution sol;
    cout << sol.celebrity(mat) << endl;
    return 0;
}
