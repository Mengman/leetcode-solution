/*
 * @lc app=leetcode.cn id=529 lang=cpp
 *
 * [529] 扫雷游戏
 */

// @lc code=start
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        return dfsSolution(board, click);
    }

    vector<vector<char>> dfsSolution(vector<vector<char>>& board, const vector<int>& click) {
        int r= click[0], c = click[1];
        int nr = board.size(), nc = board[0].size();

        if (board[r][c] == 'M') {
            board[r][c] = 'X';
            return board;
        }

        int bnum = 0;
        // top
        if (r-1 >= 0 && board[r-1][c] == 'M') bnum++;
        // top-right
        if (r-1 >= 0 && c+1 < nc && board[r-1][c+1] == 'M') bnum++;
        // right
        if (c+1 < nc && board[r][c+1] == 'M') bnum++;
        // down-right
        if (r+1 < nr && c+1 < nc && board[r+1][c+1] == 'M') bnum++;
        // down
        if (r+1 < nr && board[r+1][c] == 'M') bnum++;
        // down-left
        if (r+1 < nr && c-1 >= 0 && board[r+1][c-1] == 'M') bnum++;
        // left
        if (c-1 >= 0 && board[r][c-1] == 'M') bnum++;
        // top-left
        if (r-1 >= 0 && c-1 >= 0 && board[r-1][c-1] == 'M') bnum++;

        if (bnum > 0) {
            board[r][c] = '0' + bnum;
        } else {
            board[r][c] = 'B';
            if (r-1 >= 0 && board[r-1][c] == 'E') dfsSolution(board, {r-1, c});
            
            if (r-1 >= 0 && c+1 < nc && board[r-1][c+1] == 'E') dfsSolution(board, {r-1, c+1});
            
            if (c+1 < nc && board[r][c+1] == 'E') dfsSolution(board, {r, c+1});
            
            if (r+1 < nr && c+1 < nc && board[r+1][c+1] == 'E') dfsSolution(board, {r+1, c+1});
            
            if (r+1 < nr && board[r+1][c] == 'E') dfsSolution(board, {r+1, c});

            if (r+1 < nr && c-1 >= 0 && board[r+1][c-1] == 'E') dfsSolution(board, {r+1, c-1});

            if (c-1 >= 0 && board[r][c-1] == 'E') dfsSolution(board, {r, c-1});

            if (r-1 >= 0 && c-1 >= 0 && board[r-1][c-1] == 'E') dfsSolution(board, {r-1, c-1});
        }

        return board;
    }
};
// @lc code=end

