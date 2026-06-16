/*
 * @lc app=leetcode.cn id=1312 lang=cpp
 *
 * [1312] 让字符串成为回文串的最少插入次数
 */

// @lc code=start
class Solution {
public:
    int minInsertions(string s) {
        // 求 s 的最长回文子序列长度 t
        // 操作数量就是给剩下的字符插入相同的字符就行 操作数 = s.size() - t
        int n = s.size();
        string t(s.rbegin(), s.rend()); // t is revsersed s
        vector<vector<int>> dp(n+1, vector<int>(n+1));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n ; j++) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
                }
            }
        }
        return n - dp[n][n];
    }
};
// @lc code=end

