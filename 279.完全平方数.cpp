/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 9999);
        dp[0] = 0;
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j * j <= i; ++j) {
                dp[i] = min(dp[i], dp[i-j*j] + 1);
            }
        }
        return dp[n];
    }
};
// @lc code=end

