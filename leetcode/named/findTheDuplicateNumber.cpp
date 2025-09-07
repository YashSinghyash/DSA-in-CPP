#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;


// Space =  O(n)
// int main() {
//     vector <int> nums = {1,3,4,2,2};
//     unordered_set <int>s;
//     for (int val : nums){
//         if (s.find(val)!=s.end()){
//             cout << val;
//         }

//         s.insert(val);
//     }

//     return 0;
// }

int main(){
    vector <int> nums = {1,3,4,2,2};
    int slow = nums[0];
    int fast = nums[0];

    do {
        slow = nums[slow] ;
        fast = nums[nums[fast]] ;
    } while (slow != fast);

    slow = nums[0];

    while (slow != fast){
        slow = nums[slow];
        fast = nums[fast];
    }
    cout << slow;

    return 0;
}