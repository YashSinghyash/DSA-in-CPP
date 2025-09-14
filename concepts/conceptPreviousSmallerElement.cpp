#include <iostream>
#include <vector>
#include <stack>


using namespace std;

int main(){

    vector <int> ans;
    stack <int> s;
    vector <int> arr = {3,1,0,8,6};
    for (int i = 0 ; i < arr.size() ; i++){
        while (s.size()> 0 && s.top()>= arr[i]){
            s.pop();
        }

        if (s.empty()){
            ans.push_back(-1);
        }

        else {
            ans.push_back(s.top());
        }

        s.push(arr[i]);


    }

    for (int val : ans){
        cout << val <<" ";
    }
}