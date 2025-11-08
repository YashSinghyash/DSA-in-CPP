#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector <int> nums(n);
    for (int i = 0 ; i < n ; i++){
        cin >> nums[i];
    }

    // for (int val : nums){
    //     cout << val <<" ";
    // }
    // 4 5 2 3 1 9
    // (second largest, largest)
    // 4 (-i , -i) => (-i  ,4)
    // 5 => (4 , 5) , 2=> (4 , 5) , (4,5)
    // 9 => (5 , 9)



    int larget = INT_MIN;
    int slargest = INT_MIN;
    for (int val : nums){
        if (val > slargest){
            if (val > larget){
                slargest = larget;
                larget = val;
            }
            else {
                slargest = val;
            }
            
        }
    }

    cout << slargest;
    
            


        
}