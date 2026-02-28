/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        return diagnoalDP(s);
        
        // return downUpDP(s);
    }

    int diagnoalDP(string& s) {
        int n = s.length();

        // 记录 i~j 之间的最长回文子子字符串长度
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        for(int i = 0; i < n - 1; i++) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = 2;
            } else {
                dp[i][i+1] = 1;
            }
        }

        for(int len = 3; len <= n; ++len) {
            for(int i = 0; i <= n - len; ++i) { // i为左端点
                int j = i + len - 1; // j为右端点

                // 状态转移方程
                // 如果首尾相等，最大回文长度等于去掉首尾的回文长度+2
                // 否则，从左端点或者右端点字符串中选择最大的回文长度
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }

            }
        }

        return dp[0][n-1];
    }

    int downUpDP(string& s) {
        int n = s.length();

        // 记录 i~j 之间的最长回文子子字符串长度
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        for(int i = 0; i < n - 1; i++) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = 2;
            } else {
                dp[i][i+1] = 1;
            }
        }

        // 从下往上，从左往右的顺序迭代
        for(int i = n - 1; i >= 0; --i) {
            for(int j = i+1; j < n; ++j) {
                if((j-i+1) >= 3) {
                    if (s[i] == s[j]) {
                        dp[i][j] == dp[i+1][j-1] +2;
                    } else {
                        dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                    }
                }
            }
        }

        return dp[0][n-1];
    }
};
// @lc code=end

