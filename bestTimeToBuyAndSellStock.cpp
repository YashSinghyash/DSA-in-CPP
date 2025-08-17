#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> prices = {7,1,5,3,6,4};
    int maxProfit = 0;
    int bestBuy = prices[0];
    int si = prices.size();
    for (int i=1; i<si ; i++){
        if (prices[i]>bestBuy){
            maxProfit = max(maxProfit,prices[i]-bestBuy);
        } else {
            bestBuy = min(bestBuy,prices[i]);
        }
    }

    cout<< maxProfit;
}