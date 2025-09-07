#include <iostream>
using namespace std;

int main(){
    int nums[] = {2,7,11,13};
    int size = 4;
    int target = 13;
    for (int i = 0 ; i < size ; i++){
        for (int j= i+ 1 ; j < size ; j++){
            if (nums[i]+nums[j]==target){
                cout << i << " " << j;
            }
        }
    }
    return 0;
}