#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<vector<int> >arr(n,vector<int>(4));

    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < 4; j++){
            cin >> arr[i][j];
        }
    }
    
    for (int i = 0 ; i < n ; i++){
        int ans = 0;
        for (int j = 1 ; j < 4 ; j++){
            if (arr[i][0] < arr[i][j]) ans++;
        }
        cout << ans <<endl;
    }
    return 0;
}