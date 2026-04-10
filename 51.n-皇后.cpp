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
        backtracking(0, chessboard, ans);
        return ans;
    }

    void backtracking(int row, vector<vector<char>> &chessboard, vector<vector<string>> &ans)
    {
        if (chessboard.size() == row)
        {
            vector<string> sol;
            for(auto item : chessboard) {
                sol.push_back(string(item.begin(), item.end()));
            }
            ans.push_back(sol);
            return;
        }

        for(int i = 0; i < chessboard.size(); i++) {
            if (canPlaceQueen(chessboard, row, i)) {
                chessboard[row][i] = 'Q';
                backtracking(row + 1, chessboard, ans);
                chessboard[row][i] = '.';
            }
        }
    }

    bool canPlaceQueen(vector<vector<char>> &chessboard, int row, int col)
    {
        if (row == 0)
            return true;

        for (int i = row - 1; i >= 0; i--)
        {
            // 检查同一列上是否有 Q
            if (chessboard[i][col] == 'Q')
            {
                return false;
            }

            // 检查左对角线
            if (col - (row - i) >= 0 && chessboard[i][col - (row - i)] == 'Q')
            {
                return false;
            }

            // 检查右对角线
            if (col + (row - i) < chessboard.size() && chessboard[i][col + (row - i)] == 'Q') {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end
