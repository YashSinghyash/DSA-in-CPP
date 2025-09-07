#include <iostream>
#include <vector>
using namespace std;

class S{
public:
    vector<string> lC(string d){
        if(d.empty()) return {};
        vector<string> a;
        string t;
        vector<string> m={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        f(d,0,t,a,m);
        return a;
    }
private:
    void f(string &d,int i,string &t,vector<string> &a,vector<string> &m){
        if(i==d.size()){a.push_back(t); return;}
        for(char c:m[d[i]-'0']){
            t.push_back(c);
            f(d,i+1,t,a,m);
            t.pop_back();
        }
    }
};

int main(){
    S obj;
    string digits;
    cin >> digits;
    vector<string> res = obj.lC(digits);
    for(auto &s: res) cout << s << " ";
    return 0;
}
