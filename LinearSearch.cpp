#include <iostream>
using namespace std;

int main(){
    int arr[] = {4,2,7,8,1,2,5};
    int t = 8;
    int s = sizeof(arr)/sizeof(int);
    bool found = false;
    for (int i=0; i<s ; i++){
        if (arr[i] == t) {
            cout << i;
            found = true;
            break;
        }
    }

    if (!found){
        cout << -1;
    }
    return 0;

}