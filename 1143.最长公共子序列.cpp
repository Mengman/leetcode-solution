/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m  = text1.size(), n = text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));

        int ans = 0;
        for(int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    // 当 text1[i-1] != text2[j-1] 时候
                    // 最长子序列可能是 text1[i-1] 与 text2[j-2] 之间
                    // 或者 text1[i-2] 与 text2[j-1] 之间的最大
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
                ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }
};
// @lc code=end

