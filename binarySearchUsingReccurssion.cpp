#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int tar , int st , int end){
    if (st <=end){
        int mid = st + (end-st)/2;
        if (arr[mid] == tar){
            return mid;
        }

        if (arr[mid] > tar){
            return binarySearch(arr , tar , st , mid-1);
        }
        else {
            return binarySearch(arr , tar , mid+1 , end);
        }

    }
    return -1;
    
}


int main(){
    vector <int> arr = {-1,0,1,4,5,9};
    int target = 9;
    int ans = binarySearch(arr , target, 0 , arr.size()-1);
    cout << ans;


}