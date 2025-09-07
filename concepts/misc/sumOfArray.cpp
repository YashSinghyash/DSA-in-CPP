#include <iostream>
using namespace std;

int getSum(int arr[] , int size){
    if (size == 1){
        return arr[0];
    }

    else {
        int su = arr[0] + getSum(arr+1,size -1);
        return su;
    }
}



int main(){
    int arr[] = {9,2,3,4,9};
    int size = 5;

    int ans = getSum(arr,5);
    cout <<ans;
    return 0;
}