#include <iostream>
using namespace std;

int binarySearch(int arr[] , int a , int b){

    while(a <= b){

        int m = a + (b-a)/2;
        if (arr[m] > arr[m-1] && arr[m] > arr[m+1] ){
            return m;
        }
        else if (arr[m]<arr[m-1]){
            b = m -1 ;
        
        } else {
            a = m+1;
        }

    } 

    return -1;
}
int main(){
    
}
