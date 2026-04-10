/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N 皇后 II
 */

// @lc code=start
class Solution {
public:
    int totalNQueens(int n) {
        vector<int> chessboard(n, -1); // 记录每行 Queue 落子的位置
        return backtrack(0, chessboard);
    }

    int backtrack(int row, vector<int>& chessboard) {
        if(chessboard.size() == row) {
            return 1;
        }

        int ans = 0;
        for(int i = 0; i < chessboard.size(); ++i) {
            if(canPlaceQueen(chessboard, row, i)) {
                chessboard[row] = i;
                ans += backtrack(row+1, chessboard);
                chessboard[row] = -1;
            }
        }

        return ans;
    }

    bool canPlaceQueen(vector<int> &chessboard, int row, int col)
    {
        if (row == 0)
            return true;

        for (int i = row - 1; i >= 0; i--)
        {
            // 检查同一列上是否有 Q
            if (chessboard[i] == col)
            {
                return false;
            }

            // 检查左对角线
            if (col - (row - i) >= 0 && chessboard[i] == col - (row - i))
            {
                return false;
            }

            // 检查右对角线
            if (col + (row - i) < chessboard.size() && chessboard[i] == col + (row - i)) {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

