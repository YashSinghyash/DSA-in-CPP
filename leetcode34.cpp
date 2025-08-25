#include <iostream>
using namespace std;

int first(int nums[], int target , int end){
    int st = 0 ;
    int idx = -1;
    while (st <= end){
        int mid = st + (end-st)/2;
        if (nums[mid]==target){
            idx = mid;
            end = mid-1;
        } 
        else if (nums[mid]>target){
            end = mid -1 ;
        }
        else {
            st = mid + 1;
        }
    }
    return idx;

}


int last(int nums[], int target, int end){
    int st = 0 ; 
    int idx = -1;
    while (st <= end){
        int mid = st + (end-st)/2;
        if (nums[mid]==target){
            idx = mid;
            st = mid+1;
        } 
        else if (nums[mid]>target){
            end = mid -1 ;
        }
        else {
            st = mid + 1;
        }
    }
    return idx;

}


int main(){
    int arr[] = {5,7,7,8,8,10};
    int target = 8;
    int siz = sizeof(arr)/sizeof(arr[0]);

    int fi = first(arr, target,siz-1);
    int la = last(arr,target,siz-1);

    cout << fi << " " << la;

}