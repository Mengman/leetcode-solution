/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 */

// @lc code=start
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // 方法一：回溯法 超时
        // return backtrack(matrix);

        return dpSolution(matrix);
    }

    int dpSolution(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        // 记录每个单元格最长路径长度
        vector<vector<int>> dp(row, vector<int>(col, 0));
        int ans = 0;

        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                ans = max(ans, dfs(matrix, i, j, dp));
            }
        }
        return ans;
    }


    int dfs(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& dp) {
        if (dp[r][c] != 0) return dp[r][c];

        dp[r][c]++;

        if(r - 1 >= 0 && matrix[r-1][c] > matrix[r][c]) {
            dp[r][c] = max(dp[r][c], dfs(matrix, r-1, c, dp) + 1);
        }

        if(r+1 < matrix.size() && matrix[r+1][c] > matrix[r][c]) {
            dp[r][c] = max(dp[r][c], dfs(matrix, r+1, c, dp)+1);
        }

        if(c-1 >= 0 && matrix[r][c-1] > matrix[r][c]) {
            dp[r][c] = max(dp[r][c], dfs(matrix, r, c-1, dp)+1);
        }

        if(c+1 < matrix[0].size() && matrix[r][c+1] > matrix[r][c]) {
            dp[r][c] = max(dp[r][c], dfs(matrix, r, c+1, dp)+1);
        }

        return dp[r][c];
    }

    int backtrack(vector<vector<int>>& matrix) {
        vector<int> path;
        int ans = 0;
        int row = matrix.size();
        int col = matrix[0].size();

        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                path.push_back(matrix[i][j]);
                findPath(matrix, i, j, path, ans);
                path.clear();
            }
        }

        return ans;
    }

    void findPath(vector<vector<int>>& matrix, int r, int c, vector<int>& path, int& ans) {
        bool isEndPoint = true;

        // 上
        if(r - 1 >= 0 && matrix[r-1][c] > matrix[r][c]) {
            isEndPoint =false;

            path.push_back(matrix[r-1][c]);
            findPath(matrix, r-1, c, path, ans);
            path.pop_back();
        }

        // 下
        if (r + 1 < matrix.size() && matrix[r+1][c] > matrix[r][c]) {
            isEndPoint =false;

            path.push_back(matrix[r+1][c]);
            findPath(matrix, r+1, c, path, ans);
            path.pop_back();
        }

        // 左
        if (c+1 < matrix[0].size() && matrix[r][c+1] > matrix[r][c]) {
            isEndPoint = false;

            path.push_back(matrix[r][c+1]);
            findPath(matrix, r, c+1, path, ans);
            path.pop_back();
        }

        // 右
        if (c-1 >= 0 && matrix[r][c-1] > matrix[r][c]) {
            isEndPoint =false;

            path.push_back(matrix[r][c-1]);
            findPath(matrix, r, c-1, path, ans);
            path.pop_back();
        }

        if (isEndPoint && path.size() > ans) {
            ans = path.size();
        }
    }
};
// @lc code=end

