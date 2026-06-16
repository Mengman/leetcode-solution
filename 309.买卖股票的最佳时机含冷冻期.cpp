/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n < 2)
            return 0;
        // dp[0] 第 i 天持股情况下的最大收益
        // dp[1] 第 i 天冷冻期不持股情况下的最大收益
        // dp[2] 第 i 天非冷冻期不持股情况下的最大收益
        vector<int> dp(3, 0);
        dp[0] = -prices[0];

        for (int i = 1; i < n; i++)
        {
            // 第 i 天持股: max(前一天持股, 前一天非冷冻期今天买入)
            int dp0 = max(dp[0], dp[2] - prices[i]);
            // 第 i 天冷冻期不持股，今天卖出
            int dp1 = dp[0] + prices[i];
            // 第 i 天非冷冻期不持股 max(前一天冷冻期，前一天非冷冻期)
            int dp2 = max(dp[1], dp[2]);

            dp[0] = dp0;
            dp[1] = dp1;
            dp[2] = dp2;
        }

        return max(dp[1], dp[2]);
    }
};
// @lc code=end
