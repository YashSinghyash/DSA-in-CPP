#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int>arr(n);
    for (int i = 0 ; i < n ;i++){
        cin >> arr[i];
    }

    int ans = 1;
    int count =1;

    if (n==1) cout << 1;

    else{
        for (int i = 1 ; i < n ; i++){
            if (arr[i]>=arr[i-1]) {
                count++;
            }
            else{
                ans = max(ans,count);
                count = 1;
            }

        }
        ans = max(ans,count);

        cout << ans;
    }


}
