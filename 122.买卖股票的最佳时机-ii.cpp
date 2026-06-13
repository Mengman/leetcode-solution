/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n][2];
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for(int i = 1; i < n; i++) {
            // 第 i 天没有持股: max(前一天没有持股, 前一天持股今天抛售)
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            // 第 i 天有持股: max(前一天没有持股 今天买入, 前一天持股到今天)
            dp[i][1] = max(dp[i-1][0] - prices[i], dp[i-1][1]);
        }

        return dp[n-1][0];
    }
};
// @lc code=end

