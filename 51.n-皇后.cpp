/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<vector<char>> chessboard;
        for(int i = 0; i < n; i++) {
            chessboard.push_back(vector<char>(n, '.'));
        }
        backtracking(n, 0, chessboard, ans);
        return ans;
    }

    void backtracking(int n, int row, vector<vector<char>> &chessboard, vector<vector<string>> &ans)
    {
        if (chessboard.size() == n)
        {
            vector<vector<string>> sol;
            for(auto item : chessboard) {
                sol.push_back(string(item.begin(), item.end()))
            }
            ans.push_back(chessboard);
            return;
        }

        for(int i = 0; i < n; i++) {
            if (canPlaceQueen(chessboard, row, i, n)) {
                chessboard[row][i] = 'Q';
                backtracking(n, row + 1, chessboard, ans);
                chessboard[row][i] = '.';
            }
        }
    }

    bool canPlaceQueen(vector<vector<char>> &chessboard, int row, int col, int n)
    {
        if (row == 0)
            return true;

        for (int i = row - 1; i >= 0; i--)
        {
            if (chessboard[i][col] == 'Q')
            {
                return false;
            }

            if (col - (row - i) >= 0 && chessboard[i][col - (row - i)] == 'Q')
            {
                return false;
            }

            if (col + (row - i) < n && chessboard[i][col + (row - i)] == 'Q') {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end
