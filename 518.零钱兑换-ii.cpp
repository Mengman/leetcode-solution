/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // 完全背包问题

        // 先做可行性检查，因为在无法凑出 amount 的情况下，完全背包问题因为可以无限
        // 抽取硬币，可能会导致整数溢出。
        vector<bool> reachable(amount+1, false);
        reachable[0] = true;
        for(int coin : coins) {
            for(int j = coin; j <= amount; ++j) {
                // 使用硬币面额 coin 时候，如果 j-coin 已经凑出来了
                // 那么 j 也可以凑出来
                if(reachable[j - coin]) reachable[j] = true;
            }
        }

        if(!reachable[amount]) return 0;

        // return solution2d(amount, coins);

        return solution1d(amount, coins);
    }

    int solution2d(int amount, vector<int>& coins) {
        int n = coins.size();
        // 测试用例 30、31 在long long 上都会溢出，
        // 必须使用 unsigned long long 
        vector<vector<unsigned long long>> dp(n+1, vector<unsigned long long>(amount+1, 0));
        dp[0][0] = 1;

        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j <= amount; ++j) {
                if (j < coins[i-1]) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]];
                }
            }
        }
        return (int)dp[n][amount];
    }

    int solution1d(int amount, vector<int>& coins) {
        int n = coins.size();
        // 测试用例 30 31 在long long 上都会溢出，
        // 必须使用 unsigned long long 
        vector<unsigned long long> dp(amount+1, 0);
        dp[0] = 1;

        for(int& coin : coins) {
            for(int j = coin; j <= amount; ++j) {
                dp[j] += dp[j - coin];
            }
        }

        return (int)dp[amount];
    }
};
// @lc code=end

