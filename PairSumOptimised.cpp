#include <iostream>
using namespace std;

int main(){
    int nums[] = {2,7,11,13};
    int size = 4;
    int target = 9 ;
    int i = 0 , j = size -1 ;
    while (i<j){
        int sum = nums[i] + nums[j];
        if (sum > target){
            j--;
        }
        else if (sum < target){
            i++;
        }
        else{
            cout << i << " " << j;
            break;
        }
    }
}