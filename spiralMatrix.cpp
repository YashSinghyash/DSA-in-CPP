#include <iostream>
#include <vector>
using namespace std;

int main(){
    int mat[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int sr = 0;
    int er = 3-1;
    int sc = 0;
    int ec = 4-1;   
    vector <int> ans;

    while(sr <= er && sc <=ec){
        for (int j = sc ; j <= ec ; j++){
            ans.push_back(mat[sr][j]);
        }
        for (int i = sr+1 ; i <= er ; i++){
            ans.push_back(mat[i][ec]);
        }
        for (int j = ec-1 ; j >= sc ; j--){
            if (sr == er){
                break;
            }
            ans.push_back(mat[er][j]);
        }
        for (int i = er-1 ; i >= sr+1 ; i--){
            if (sc == ec){
                break;
            }
            ans.push_back(mat[i][sc]);
        }

        sr++ ; ec--;er--;sc++;
    }

    for (int i = 0 ; i < ans.size(); i++){
        cout << ans[i] <<" ";
    }
    return 0;
}