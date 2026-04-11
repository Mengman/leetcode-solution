/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution
{
private:
    bool visited_row[9][9];
    bool visited_col[9][9];
    bool visited_block[3][3][9];
    vector<pair<int, int>> blanks;

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        int nr = board.size();
        int nc = board[0].size();

        memset(visited_row, false, sizeof(visited_row));
        memset(visited_col, false, sizeof(visited_col));
        memset(visited_block, false, sizeof(visited_block));

        for (int r = 0; r < nr; ++r)
        {
            for (int c = 0; c < nc; ++c)
            {
                if (board[r][c] == '.')
                {
                    blanks.push_back({r, c});
                    continue;
                }

                int v = board[r][c] - '0' - 1;
                visited_row[r][v] = true;
                visited_col[c][v] = true;
                visited_block[r / 3][c / 3][v] = true;
            }
        }

        backtrack_dfs(board, 0);
    }

    bool backtrack_dfs(vector<vector<char>> &board, int n)
    {
        auto [r, c] = blanks[n];
        for (int v = 0; v < 9; ++v)
        {
            if (visited_row[r][v] || visited_col[c][v] || visited_block[r/3][c/3][v])
                continue;

            visited_row[r][v] = true;
            visited_col[c][v] = true;
            visited_block[r/3][c/3][v] = true;
            board[r][c] = v + '0' + 1;

            if (n == blanks.size() - 1)
                return true;

            bool res = backtrack_dfs(board, n + 1);

            if (res)
            {
                return true;
            }

            visited_row[r][v] = false;
            visited_col[c][v] = false;
            visited_block[r/3][c/3][v] = false;
            board[r][c] = '.';
        }

        return false;
    }
};
// @lc code=end
