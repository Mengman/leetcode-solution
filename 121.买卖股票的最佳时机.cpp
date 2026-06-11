/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int highestPrices = prices[n-1];
        int ans = 0;
        for(int i = n-2; i >= 0; i--) {
            highestPrices = max(highestPrices, prices[i]);
            ans = max(highestPrices - prices[i], ans);
        }

        return ans;
    }
};
// @lc code=end

