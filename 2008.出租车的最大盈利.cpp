/*
 * @lc app=leetcode.cn id=2008 lang=cpp
 *
 * [2008] 出租车的最大盈利
 */

// @lc code=start
class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int m = rides.size();

        if (m < 2) return calcPrice(rides[0]);

        sort(rides.begin(), rides.end(), [](const vector<int>& a, vector<int>&b) {
            return a[1] < b[1];
        });
        vector<long long> dp(n+1, 0);

        int k = 0;
        for(int i = 1; i < n+1; ++i) {
            // 在 i 地点，有两种选择
            // 没有搭载以 i 地点为终点的乘客： dp[i] = dp[i-1]
            // 搭载以 i 地点为终点的乘客：    dp[i] = 当前订单起点收益 + 当前订单的收益
            // 两种情况选择收益最大的一种
            dp[i] = dp[i-1];
            // 避免重复计算，只计算以 i 为终点的订单
            for(; k < m; ++k) {
                if(rides[k][1] > i) break;
                
                dp[i] = max(dp[i], dp[rides[k][0]] + calcPrice(rides[k]));
            }
        }

        return dp[n];
    }

    long long calcPrice(vector<int>& r) {
        return r[1] - r[0] + r[2]; 
    }
};
// @lc code=end

