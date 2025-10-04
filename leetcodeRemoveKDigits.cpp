#include <iostream>
#include <string>
using namespace std;





class Solution {
public:
    string removeKdigits(string num, int k) {
        string s;


        for (char c : num){
            while (!s.empty() && k > 0 && s.back()> c ){
                s.pop_back();
                k--;
            }

            s.push_back(c);
        }

        while (k > 0 && !s.empty()){
            s.pop_back();
            k--;
        }

        int i = 0 ; 
        while (i < s.size() && s[i] == '0'){
            i++;
        }

        s = s.substr(i);

        if (s.empty()) return "0";
        else return s;
    }
};