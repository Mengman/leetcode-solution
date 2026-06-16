/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // 买入不需要付手续费；卖出需要付手续费
        int n = prices.size();
        if (n < 2) return 0;

        vector<int> dp(2, 0);
        // 第 i 天持股
        dp[1] = -prices[0];

        for(int i = 1; i < n; i++) {
            int dp0 = max(dp[0], dp[1] + prices[i] - fee);
            int dp1 = max(dp[0] - prices[i], dp[1]);

            dp[0] = dp0;
            dp[1] = dp1;
        }

        return dp[0];
    }
};
// @lc code=end

