#include <iostream>
using namespace std;

int main(){
    int nums[] = {1,2,3,4};
    int siz = 4;
    int suff=1;
    int ans[siz];
    for (int i = 0 ; i < siz ; i++){
        if (i==0){
            ans[0]=1;
        }else{
        ans[i] = ans[i-1] * nums[i-1];
        }
    }

    for (int j = siz-2 ; j >= 0 ; j--){
        suff *= nums[j+1];
        ans[j] = ans[j] * suff;
    }
    for (int a : ans){
        cout << a << " ";
    }
}