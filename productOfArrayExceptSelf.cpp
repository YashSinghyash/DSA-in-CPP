#include <iostream>
using namespace std;

int main(){
    int nums[] = {1,2,3,4};
    int ans[4];
    int siz = sizeof(nums)/sizeof(nums[0]);
    for (int i = 0 ; i < siz ; i++){
        int prod = 1;
        for (int j =0 ; j < siz ; j++){
            if (i==j){
                continue;
            }
            else{
                prod = prod * nums[j];
            }
            
        }
        ans[i] = prod;

    }

    for (int k = 0 ; k < siz ; k++){
        cout << ans[k] <<" ";
    };

    return 0;
}