class Solution {
public:
    void backtracking(vector <string> &board , int row , int n ,  vector<vector<string>> &ans){

        if (row == n){
            ans.push_back(board);
            return;
        }

        for (int j = 0; j < n ; j++){
            if(isSafe(board, row , j , n)){
                board[row][j] = 'Q';
                backtracking(board, row+1 , n , ans);
                board[row][j] = '.';
            }
        }
    }
    bool isSafe(vector <string> &board , int row , int col , int n){
        for (int j = 0 ; j < n ; j++){
            if (board[row][j]== 'Q'){
                return false;
            }
        }
        for (int j = 0 ; j < n ; j++){
            if (board[j][col]== 'Q'){
                return false;
            }
        }
        for (int i = row , j = col ; j >= 0 && i >= 0 ; j--, i--){
            if (board[i][j]== 'Q'){
                return false;
            }
        }
        for (int i = row , j = col ; i >= 0 && j < n ; j++ , i--){
            if (board[i][j]== 'Q'){
                return false;
            }
        }

        return true;

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board (n,string(n,'.'));
        vector<vector<string>> ans;
        backtracking (board , 0 , n , ans);
        return ans;
        
    }
};