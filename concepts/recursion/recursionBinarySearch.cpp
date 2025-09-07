#include <iostream>
using namespace std;

bool BinarySearch(int arr[] , int st , int end , int key){
    if (st > end){
        return false;
    }


    int mid = st + (end - st)/2;

    if (arr[mid]==key) return true;
    if (arr[mid]>key){
        bool ans = BinarySearch(arr , st , mid -1 , key);
        return ans;
    }
    else {
        bool ans = BinarySearch(arr , mid+1 , end , key);
        return ans;
    }
}


int main(){
    int arr[] = {1,4,5,6,7,10};
    int key = 6;

    bool ans = BinarySearch(arr,0,5,10);
    cout << ans;
    return 0;
}