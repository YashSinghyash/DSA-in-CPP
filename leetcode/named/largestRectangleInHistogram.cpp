#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& ht) {
        int n = ht.size();

        vector<int> left(n,0);
        vector<int> right(n,0);

        stack<int> s;

        for (int i = 0 ; i < n ; i++){
            while (s.size() > 0 && ht[s.top()] >= ht[i]){
                s.pop();
            }

            left[i] = s.empty() ? -1 : s.top();

            s.push(i);
        }

        while (!s.empty()){
            s.pop();
        }

        for (int i = n-1 ; i >= 0 ; i--){
            while (s.size() > 0 && ht[s.top()] >= ht[i]){
                s.pop();
            }

            right[i] = s.empty()? n : s.top();

            s.push(i);
        }
        int ans = 0;

        for (int i = 0 ; i < n; i++){
            int wid = right[i] - left[i] - 1;
            int curArea = ht[i] * wid;

            ans = max(curArea, ans);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << sol.largestRectangleArea(heights) << endl;
    return 0;
}
