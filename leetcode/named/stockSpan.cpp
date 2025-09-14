#include <iostream>
#include <vector>
#include <stack>


using namespace std;

int main(){

    vector <int> prices = {100,80,60,70,60,75,85};

    vector <int> ans(prices.size());
    stack <int>s;

    for (int i = 0 ; i < prices.size() ; i++){
        while (s.size()> 0 && prices[s.top()] <= prices[i]){
            s.pop();
        }

        if (s.size()== 0) ans[i] = i+1;

        else {
            ans[i] = i-s.top();
            
        }
        s.push(i);
    }

    for (int val : ans){
        cout << val <<" ";
    }



    return 0;
}