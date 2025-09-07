#include <iostream>
using namespace std;


bool linearSearch(int arr[] , int key , int size){
    if (size == 0 ){
        return false;
    }

    if (size == 1){
        if (arr[0]==key){
            return true;
        } else return false;
    }

    else {
        if (arr[0]==key){
            return true;
    } else {
        bool ans = linearSearch(arr+1 , key , size-1);
        return ans;
    }
}
}


int main(){
    int arr[] = {1,4,5,6,7};
    int size = sizeof(arr)/sizeof(int);
    bool findKey = linearSearch(arr,50,size);
    cout << findKey;
}