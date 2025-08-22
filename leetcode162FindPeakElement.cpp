#include <iostream> 
using namespace std;


int solution(int arr[],int siz){
    int st = 0;
    int end = siz-1;
    if (siz ==0){
        return 0;

    }
    if (siz ==1){
        return 0;

    }
    if (arr[st]>arr[st+1]){
        return st;

    }
    if (arr[end]>arr[end-1]){
        return end;

    }
    if (siz > 2){
        while (st<=end){

        int mid = st + (end-st)/2;

        if ((mid == 0 || arr[mid] > arr[mid-1]) &&
    (mid == siz-1 || arr[mid] > arr[mid+1])) {
    return mid;
}

        if (arr[mid]<arr[mid+1]){
            st = mid+1;
        }
        else{
            end = mid -1;
            
        }
    }
    }

    return -1;
}
int main(){
    int arr[] = {1,2,1,3,5,6,4};
    int siz = sizeof(arr)/sizeof(arr[0]);
    int ans = solution(arr,siz);
    cout << ans;
}
