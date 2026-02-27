/*
 * @lc app=leetcode.cn id=879 lang=cpp
 *
 * [879] 盈利计划
 */

// @lc code=start
class Solution {
    const int mod = 1e9+7;
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        // return solution3d(n, minProfit, group, profit);

        return solution2d(n, minProfit, group, profit);

    }

    int solution3d(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = group.size();
        // 状态数组: 记录第i个方案用n个员工利润率至少为k时候的方案总数
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(minProfit+1, 0)));
        dp[0][0][0] = 1;

        for(int i = 1; i <= m; ++i) {
            for(int j = 0; j <= n; ++j) {
                for(int k = 0; k <= minProfit; ++k) {
                    // 不选择方案 i
                    if (j < group[i-1]) {
                        dp[i][j][k] = dp[i-1][j][k];
                    } else  {
                        // 选择方案 i
                        // max(0, k - profit[i-1]) 确保利润大于等于0
                        dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j - group[i-1]][max(0, k - profit[i-1])];
                        dp[i][j][k] %= mod;
                    }
                }
            }
        }

        int ans = 0;
        // 最终答案等于所有工人数情况下方案数和
        for(int i = 0; i <= n; ++i) {
            ans = (ans + dp[m][i][minProfit]) % mod;
        }
        return ans;
    }

    int solution2d(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        // 优化 solution3d
        // dp[i][*][*] 只与 dp[i-1][*][*]相关，将3维数值优化为2维数组
        int m = group.size();
        vector<vector<int>> dp(n+1, vector<int>(minProfit+1, 0));
        dp[0][0] = 1;

        for(int i = 1; i <= m; ++i) {
            for(int j = n; j >= 0; --j) {
                for(int k = minProfit; k >= 0; --k) {
                    if(j >= group[i-1]) {
                        dp[j][k] += dp[j-group[i-1]][max(0, k - profit[i-1])];
                        dp[j][k] %= mod;
                    }
                }
            }
        }

        int ans = 0;
        for(int i = 0; i <= n; ++i) {
            ans = (ans + dp[i][minProfit]) % mod;
        }

        return ans;
    }
};
// @lc code=end

