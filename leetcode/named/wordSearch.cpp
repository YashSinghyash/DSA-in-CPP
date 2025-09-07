#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool help(vector<vector<char>>& board , string word , int m , int n , string &ans , int idx ){

    if (m < 0 || n < 0 || m >= board.size() || n >= board[0].size()){
        return false;
    } else {
        if (board[m][n] == word[idx]){
            ans.push_back(board[m][n]);
        } else {
            return false;
        }
        
    }

    if (word == ans){
        return true;
    }


    bool a1 =help(board , word, m+1, n , ans , idx+1);
    ans.pop_back();
    bool a2= help(board , word, m-1, n , ans , idx+1);
    ans.pop_back();
    bool a3 = help(board , word, m, n-1 , ans,idx+1);
    ans.pop_back();
    bool a4 = help(board , word, m, n+1 , ans,idx+1);
    ans.pop_back();

    return (a1||a2||a3||a4);

}

bool findmn(vector<vector<char>>& board , string word , string &ans ){
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == word[0]){
                return help(board, word, i , j , ans , 0);
            }

            else {
                continue;;
            }
    }
}

return false;

}


int main(){
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    string ans;
    return 0;
}