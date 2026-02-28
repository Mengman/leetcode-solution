/*
 * @lc app=leetcode.cn id=375 lang=cpp
 *
 * [375] 猜数字大小 II
 */

// @lc code=start
class Solution {
    const int INF = 0x3f3f3f3f;
public:
    int getMoneyAmount(int n) {
        // dp[i][j] 表示从 i 到 j 确保获胜的最小花费
        // n + 2 是为了防止 m - 1 或 m + 1 越界
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for(int len = 2; len <= n; ++len) {
            for(int i = 1; i <= n - len + 1; ++i) {
                int j = i + len - 1;
                dp[i][j] = INF;
                for(int m = i; m <= j; ++m) { // m是猜的数字
                    int res = m + max(dp[i][m-1], dp[m+1][j]);
                    dp[i][j] = min(dp[i][j], res);
                }
            }
        }

        return dp[1][n];
    }
};
// @lc code=end

