#include <iostream>
using namespace std;

void bubble_sort (int arr[],int n){

    
    for (int i = 0 ; i < n ; i++ ){
        bool Swap = false;
        for (int j =0 ; j < n - i - 1 ; j++){
            if (arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                Swap = true;
            }
            
        }
        if (!Swap){
                return ;
            }
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
    bubble_sort(arr,n);
    printArray(arr,n);
}