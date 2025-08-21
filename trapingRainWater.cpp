#include <iostream>
using namespace std;

int main(){
    int arr[] = {4,2,0,3,2,5};
    int siz = sizeof(arr)/sizeof(arr[0]);
    int l_wall = arr[0];
    int r_wall = arr[siz-1];
    int ar2[siz];
    for (int i = 0 ; i < siz ; i++){
        if (l_wall <= arr[i]){
            l_wall = arr[i];
        }
        ar2[i] = l_wall;
        

            
    }

    cout << endl;
    for (int i = siz-1 ; i>0;i--){
        if (r_wall < arr[i]){
            r_wall = arr[i];
        }

        ar2[i] = min(ar2[i],r_wall);

    }
    int area = 0;
    for (int i = 0 ; i < siz ; i++){
        area = area + (ar2[i]-arr[i]);
    }
cout << area;
}