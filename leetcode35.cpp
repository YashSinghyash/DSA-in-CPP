#include <iostream>
using namespace std;

int main(){
    int arr[] = {1,3,5,6};
    int target = 5;
    int siz = 4;
    int st = 0, end = siz - 1;

    while (st <= end){
        int mid = st + (end - st) / 2;
        if (arr[mid] == target){
            cout << mid;
            return 0;
        }
        else if (arr[mid] > target){
            end = mid - 1;
        } else {
            st = mid + 1;
        }
    }

    cout << st;
    return 0;
}
