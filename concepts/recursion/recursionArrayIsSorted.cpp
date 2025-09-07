#include <iostream>
using namespace std;

bool isSorted(int arr[],int size){
    if (size <=1){
        return true;
    }

    if (arr[0] > arr[1]) return false;

    else{
        bool ans = isSorted(arr+1,size-1);
        return ans;
    }
}

int main(){
    int arr[] = {1,3,10,5,9};
    bool isSor = isSorted(arr,5);

    cout << isSor;

}