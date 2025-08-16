#include <iostream>
using namespace std;

int main(){
    int arr[] = {3,-4,5,4,-1,7,8};
    int size = 7;
    int max_sum = INT_MIN; 
    int cur_sum = 0;
    for (int i = 0  ; i< size ; i++ ){
        cur_sum += arr[i];
        max_sum = max(max_sum,cur_sum);
        if (cur_sum < 0){
            cur_sum = 0;
        }
    }
    cout << max_sum ;
}
