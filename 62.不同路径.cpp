/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m < 2 || n < 2) return 1;
        
        // 解法1：坐标动态规划
        // vector<vector<int>> dp(m, vector<int>(n, 1));

        // for(int i = 1; i < m; ++i) {
        //     for(int j = 1; j < n; ++j) {
        //         dp[i][j] = dp[i-1][j] + dp[i][j-1];
        //     }
        // }
        // return dp[m-1][n-1];

        // 解法2：优化 dp 数组的大小
        vector<int> dp(n, 1);
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                dp[j] += dp[j-1];
            }
        }

        return dp[n-1];
    }
};
// @lc code=end

