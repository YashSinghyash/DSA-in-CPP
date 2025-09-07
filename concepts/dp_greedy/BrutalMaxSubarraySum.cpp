#include <iostream>
using namespace std;

int main(){
    int arr[] = {3,-4,5,4,-1,7,8};
    int size = sizeof(arr)/sizeof(int);
    int max_sum = 0;
    for (int i=0 ; i<size ; i++){
        int sum = 0;
        for (int j=i; j<size ; j++){
            sum += arr[j];
            max_sum = max(sum,max_sum);
            
        }
    }
    cout << max_sum;
    return 0;
}