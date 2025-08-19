// Leetcode question solve karna hai in log n time complexity;
#include <iostream>
using namespace std;

int main(){
    int arr[] = {0,3,8,9,5,2};
    int siz = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0 ; i < siz ; i++){
        if (arr[i-1]<arr[i] && arr[i] > arr[i+1] ){
            cout << i ;
            return 0;
        }
    }

    return -1;
}