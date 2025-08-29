#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main(){

    vector <vector<int> > grid = {{9,1,7},{8,9,2},{3,4,6}};
    vector <int> ans;
    unordered_set <int> s;
    int a , b ;
    int n = grid.size();
    int expSum = 0;
    int actSum= 0;

    for (int i = 0 ; i < n ; i++){
        for (int j = 0; j < n ; j++){
            actSum += grid[i][j];
            if (s.find(grid[i][j]) != s.end()){
                a = grid[i][j];
                ans.push_back(a);
            }
            s.insert(grid[i][j]);
        }
    }

    expSum = ((n*n) * ((n*n)+1))/2;
    b = expSum - actSum + a;

    ans.push_back(b);

    for (int i = 0 ; i <ans.size() ; i++){
        cout << ans[i];
    }

}