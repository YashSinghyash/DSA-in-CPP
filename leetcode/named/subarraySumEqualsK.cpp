#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    vector<int> arr = {9,4,20,3,10,5};
    unordered_map <int,int> m;
    int target = 18;
    int n = arr.size();
    int count = 0;
    vector <int> ps (n,0);
    ps[0]= arr[0];

    for (int i = 1 ; i < n ; i++){
        ps[i] = ps[i-1] + arr[i];

    }
    
    for (int j = 0 ; j < n ; j++){
        if (ps[j] == target) count++;

        int val = ps[j] - target;
        if (m.find(val) != m.end()){
            count += m[val];
        }

        if (m.find(ps[j]) == m.end()){
            m[ps[j]] =0;
        }

        m[ps[j]]++;
    }

    cout << count;
    return 0;
}