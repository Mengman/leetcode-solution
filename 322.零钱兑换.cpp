/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
    const int INF = 0x3f3f3f3f;
public:
    int coinChange(vector<int>& coins, int amount) {
        // 完全背包问题
        // return solution2d(coins, amount);

        return solution1d(coins, amount);

    }

    int solution2d(vector<int>& coins, int amount) {
        int n = coins.size();
        // 状态数组记录使用(0~i-1)种硬币，累计金额为 m 的硬币数
        vector<vector<int>> dp(n+1, vector<int>(amount+1, INF));
        dp[0][0] = 0;

        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j <= amount; ++j) {
                if (j < coins[i-1]) {
                    // 不选择硬币 i
                    dp[i][j] = dp[i-1][j];
                } else {
                    // 选择硬币 i
                    // 状态转移方程： min(不选择i硬币， 减去i硬币面值时的硬币数+1)
                    dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]] + 1);
                }
            }
        }
        return dp[n][amount] == INF ? -1 : dp[n][amount];
    }


    int solution1d(vector<int>& coins, int amount) {
        // 优化 solution2d， 使用1维 dp 数组
        int n = coins.size();
        vector<int> dp(amount+1, INF);
        dp[0] = 0;
        for(int i = 1; i <= n; ++i) {
            // 完全背包问题不用考虑重复选择
            for(int j = 0; j <= amount; ++j) {
                if (j >= coins[i-1]) {
                    dp[j] = min(dp[j], dp[j-coins[i-1]] + 1);
                }
            }
        }

        return dp[amount] == INF ? -1 : dp[amount];
    }
};
// @lc code=end

