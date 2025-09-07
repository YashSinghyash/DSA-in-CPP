#include <iostream>
using namespace std;

int main(){
    int arr[] = {4,2,7,8,1,2,5};
    int start = 0;
    int end = sizeof(arr)/sizeof(int) - 1;
    while (start < end ){
        swap(arr[start],arr[end]);
        start++;
        end--;

    }

    for (int i = 0 ; i < 7 ; i++ ){
        cout << arr[i] <<" ";
    }
}