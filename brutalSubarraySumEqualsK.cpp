#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> arr = {9,4,20,3,10,5};
    int count = 0;
    int tar = 33;

    for (int i =0 ; i < arr.size() ; i++){
        int sum = 0;
        for (int j=i ; j < arr.size() ; j++){
            sum += arr[j];
            if (sum == tar) count++;
        }
    }

    cout << count;
    return 0;
}