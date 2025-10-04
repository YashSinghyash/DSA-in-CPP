#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> s;
        for (int i = 0 ; i < tokens.size() ; i++){
            if (tokens[i] == "+" || tokens[i]=="-" || tokens[i]=="/" || tokens[i]=="*"){
                string x = tokens[i];
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                if (x == "*") s.push(a * b);
                else if (x == "+") s.push(a+b);
                else if (x == "-") s.push(a-b);
                else if (x == "/") s.push(a/b);
            }

            else {
                s.push(stoi(tokens[i]));
            }
        }

        return s.top();


    }
};