#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int r, int c, int n, int expVal) {
        if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != expVal) 
            return false;

        if (grid[r][c] == (n * n) - 1) 
            return true;

        bool a1 = isValid(grid, r - 2, c + 1, n, expVal + 1);
        bool a2 = isValid(grid, r - 1, c + 2, n, expVal + 1);
        bool a3 = isValid(grid, r + 1, c + 2, n, expVal + 1);
        bool a4 = isValid(grid, r + 2, c + 1, n, expVal + 1);
        bool a5 = isValid(grid, r + 2, c - 1, n, expVal + 1);
        bool a6 = isValid(grid, r + 1, c - 2, n, expVal + 1);
        bool a7 = isValid(grid, r - 1, c - 2, n, expVal + 1);
        bool a8 = isValid(grid, r - 2, c - 1, n, expVal + 1);

        return (a1 || a2 || a3 || a4 || a5 || a6 || a7 || a8);
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        return isValid(grid, 0, 0, grid.size(), 0);
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {0,  5, 14,  9, 20},
        {15, 8, 19,  4, 13},
        {6,  1, 24, 21, 10},
        {23,16, 7, 18,  3},
        {2, 11, 22, 17, 12}
    };
    cout << (sol.checkValidGrid(grid) ? "true" : "false") << endl;
}
