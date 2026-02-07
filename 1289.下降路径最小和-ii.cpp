/*
 * @lc app=leetcode.cn id=1289 lang=cpp
 *
 * [1289] 下降路径最小和  II
 */

// @lc code=start
class Solution {
    const int INF = 0x3f3f3f3f;
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j  < n; ++j) {
                dp[i][j] = grid[i][j];
                
                if (i - 1 >= 0) {
                    int val = INF;
                    for(int k = 0; k < n; ++k) {
                        if(k == j) continue;

                        val = min(val, dp[i-1][k]);
                    }
                    dp[i][j] += val;
                }
                
            }
        }

        int end_y = m - 1 > 0 ? m - 1 : 0;
        int ans = dp[end_y][0];
        for(int k = 0; k < n; ++k) {
            ans = min(ans, dp[end_y][k]);
        }

        return ans;
    }
};
// @lc code=end

