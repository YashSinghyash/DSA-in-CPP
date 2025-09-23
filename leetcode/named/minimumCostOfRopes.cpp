#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
  public:
    int minCost(vector<int>& arr) {
        priority_queue<long long int, vector<long long int>, greater<long long int>> pq;

        for (int i = 0; i < arr.size(); i++) {
            pq.push(arr[i]);
        }

        long long int ans = 0;

        while (pq.size() > 1) {
            long long int a = pq.top();
            pq.pop();

            long long int b = pq.top();
            pq.pop();

            long long int sum = a + b;

            ans += sum;
            pq.push(sum);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> ropes = {4, 3, 2, 6};
    cout << sol.minCost(ropes) << endl;
    return 0;
}
