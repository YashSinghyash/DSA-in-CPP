#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string str) {
        stack<char> st;

        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
                st.push(str[i]);
            }
            else {
                if (st.size() == 0) {
                    return false;
                }
                else if (st.top() == '(' && str[i] == ')' ||
                         st.top() == '{' && str[i] == '}' ||
                         st.top() == '[' && str[i] == ']') {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        return st.size() == 0;
    }
};

int main() {
    Solution solution;
    string test;

    cout << "Enter a string of parentheses/brackets/braces: ";
    cin >> test;

    if (solution.isValid(test)) {
        cout << "The string is valid." << endl;
    } else {
        cout << "The string is invalid." << endl;
    }

    return 0;
}
