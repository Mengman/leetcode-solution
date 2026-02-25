/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);

        for(int i = 1; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                // 从大到小提升效率, (i-j) 到 j
                dp[i] = max(dp[i], max((i - j) * j , (i-j) * dp[j]));
            }
        }

        return dp[n];
    }
};
// @lc code=end

