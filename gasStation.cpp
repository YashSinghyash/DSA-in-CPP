#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& a, vector<int>& b) {
        int x = 0, y = 0, z = 0, s = 0;
        for (int i = 0; i < b.size(); i++) {
            x += a[i];
            y += b[i];
            z += a[i] - b[i];
            if (z < 0) {
                s = i + 1;
                z = 0;
            }
        }
        return x < y ? -1 : s;
    }
};

int main() {
    Solution obj;
    vector<int> a = {1,2,3,4,5};
    vector<int> b = {3,4,5,1,2};
    cout << obj.canCompleteCircuit(a, b);
}
