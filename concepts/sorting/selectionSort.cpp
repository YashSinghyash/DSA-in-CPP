#include <iostream>
using namespace std;

void SelectionSort (int arr[],int n){
    for (int i = 0 ; i < n ; i++ ){
        int smallest = i;
        for (int j = i+1 ; j < n ; j++){
            if (arr[j]<arr[smallest]){
                smallest = j;
            }
        }
        swap (arr[i],arr[smallest]);
    }
}

void printArray(int arr[], int n){
    for (int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[] ={4,7,1,3,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    SelectionSort(arr,n);
    printArray(arr,n);
}