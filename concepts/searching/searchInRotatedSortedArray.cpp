#include <iostream>
using namespace std;

int main(){
    int nums[] = {3,4,5,6,7,0,1,2};
    int target = 0;
    int siz = sizeof(nums)/sizeof(nums[0]);
    int st = 0;
    int end = siz-1;
    while (st <= end){
        int mid = st + (end-st)/2;
        if (nums[mid]== target){
            cout<< mid;
            return 0;
        }
        if (nums[st]<= nums[mid]){
            if (nums[st]<=target && target<=nums[mid]){
                end = mid -1;
            }
            else{
                st = mid + 1;
            }
        }
        else {
            if (nums[mid]<= target && target <= nums[end]){
                st = mid + 1;
            }
            else {
                end = mid - 1;
            
            }
        }
    }

    return -1;

}