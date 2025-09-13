#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        queue<int> q;

        for (int i = 0; i < s.size(); i++) {
            if (m.find(s[i]) == m.end()) {
                q.push(i);
            }
            m[s[i]]++;

            while (!q.empty() && m[s[q.front()]] > 1) {
                q.pop();
            }
        }

        if (q.empty()) {
            return -1;
        }

        return q.front();
    }
};

int main() {
    Solution obj;
    cout << obj.firstUniqChar("leetcode") << endl;
    cout << obj.firstUniqChar("loveleetcode") << endl;
    cout << obj.firstUniqChar("aabb") << endl;
    return 0;
}
