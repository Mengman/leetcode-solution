/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
struct PairHash {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2>& p) const {
        // Basic hash combination
        return std::hash<T1>{}(p.first) ^ (std::hash<T2>{}(p.second) << 1);
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int nr = board.size();
        int nc = board[0].size();

        // 从四周开始检查
        for(int r = 0; r < nr; ++r) {
            if(board[r][0] == 'O') {
                dfs1(board, r, 0);
            }

            if(board[r][nc-1]=='O') {
                dfs1(board, r, nc-1);
            }
        }

        for(int c = 0; c < nc; ++c) {
            if(board[0][c] == 'O') {
                dfs1(board, 0, c);
            }

            if(board[nr-1][c] == 'O') {
                dfs1(board, nr-1, c);
            }
        }

        for(int r = 0; r < nr; r++) {
            for(int c = 0; c < nc; c++) {
                if (board[r][c] == 'A') {
                    board[r][c] = 'O';
                } else if (board[r][c] = 'O')
                {
                    board[r][c] = 'X';
                }
            }
        }


        // dfsSolution(board);
    }

    void dfs1(vector<vector<char>>& board, int r, int c) {
        int nr = board.size();
        int nc = board[0].size();

        board[r][c] = 'A';
        // top
        if(r-1 >= 0 && board[r-1][c]=='O') dfs1(board, r-1, c);

        // down
        if(r+1 < nr && board[r+1][c] == 'O') dfs1(board, r+1, c);

        // left
        if(c-1 >= 0 && board[r][c-1] == 'O') dfs1(board, r, c-1);

        // right
        if(c+1 < nc && board[r][c+1] == 'O') dfs1(board, r, c+1);
    }

    void dfsSolution(vector<vector<char>>& board) {
        int nr = board.size();
        int nc = board[0].size();

        unordered_set<pair<int, int>, PairHash> hset;
        for(int r = 0; r < nr; ++r) {
            for(int c = 0; c < nc; ++c) {
                if (board[r][c] == 'O') {
                    char res = 'X';
                    dfs(board, hset, r, c, nr, nc, res);

                    if (res == 'X') {
                        for(auto [y, x] : hset) {
                            board[y][x] = 'X';
                        }
                    }
                }
                hset.clear();
            }
        }
    }


    void dfs(vector<vector<char>>& board, unordered_set<pair<int, int>, PairHash>& hset, int r, int c, int nr, int nc, char& res) {
        hset.insert({r, c});

        if (r == 0 || r == nr - 1 || c == 0 || c == nc - 1) {
            res = 'O';
        }

        // top
        if(r-1 >= 0 && board[r-1][c] == 'O' && hset.find({r-1, c}) == hset.end()) {
            dfs(board, hset, r-1, c, nr, nc, res);
        }

        // down
        if(r+1 < nr && board[r+1][c] == 'O' && hset.find({r+1, c}) == hset.end()) {
            dfs(board, hset, r+1, c, nr, nc, res);
        }

        // left
        if(c-1 >= 0 && board[r][c-1] == 'O' && hset.find({r, c-1}) == hset.end()) {
            dfs(board, hset, r, c-1, nr, nc, res);
        }

        // right
        if(c+1 < nc && board[r][c+1] == 'O' && hset.find({r, c+1}) == hset.end()) {
            dfs(board, hset, r, c+1, nr, nc, res);
        }

        if (res != 'O') res = 'X';
    }

};
// @lc code=end

