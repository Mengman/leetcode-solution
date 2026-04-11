/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int nr = board.size();
        int nc = board[0].size();
        vector<vector<bool>> visited(nr, vector<bool>(nc, false));

        for(int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                visited[r][c] = true;
                if (backtrack(board, word, nr, nc, r, c, visited, 0)) {
                    return true;
                }
                visited[r][c] = false;
            }
        }

        return false;
    }

    bool backtrack(vector<vector<char>>& board, string& word, int nr, int nc, int r, int c, vector<vector<bool>>& visited, int wn) {
        if(board[r][c] == word[wn]) {
            if (wn == word.length() - 1) {
                return true;
            }

            // top
            if (r-1 >= 0 && !visited[r-1][c]) {
                visited[r-1][c]= true;
                if (backtrack(board, word, nr, nc, r-1, c, visited, wn+1)) return true;
                visited[r-1][c]= false;
            }

            // right
            if (c+1 < nc && !visited[r][c+1]) {
                visited[r][c+1] = true;
                if (backtrack(board, word, nr, nc, r, c+1, visited, wn+1)) return true;
                visited[r][c+1] = false;
            }

            // down
            if (r+1 < nr && !visited[r+1][c]) {
                visited[r+1][c] = true;
                if(backtrack(board, word, nr, nc, r+1, c, visited, wn+1)) return true;
                visited[r+1][c] = false;
            }

            // left
            if (c-1 >= 0 && !visited[r][c-1]) {
                visited[r][c-1] = true;
                if(backtrack(board, word, nr, nc, r, c-1, visited, wn+1)) return true;
                visited[r][c-1] = false;
            }
        }

        return false;
    }

};
// @lc code=end

