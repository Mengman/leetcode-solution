/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        // 三种变换操作可以看成
        // word1 后插入一个字符: dp[i-1][j] + 1
        // word2 后插入一个字符: dp[i][j-1] + 1
        // word1/word2 替换一个字符 dp[i-1][j-1] + 1
        int n = word1.length();
        int m = word2.length();

        if (n == 0 || m == 0) return max(n, m);

        //dp[i][j] 是 word1[0:i] 与 word2[0:j] 之间变换的最小操作数
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 0; i < n + 1; i++)
            dp[i][0] = i;
        
        for(int j = 0; j < m + 1; j++)
            dp[0][j] = j;
        
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < m+1; j++) {
                if (word1[i-1] == word2[j-1]) {
                    // min(word1[0:i-1] 插入1个字符, word2[0:j-1] 插入一个字符, word1[0:i-1] word2[0:j-1]不执行任何操作)
                    dp[i][j] = min(dp[i-1][j] + 1, min(dp[i][j-1] + 1, dp[i-1][j-1]));
                } else {
                    // min(word1[0:i-1] 插入1个字符, word2[0:j-1] 插入一个字符, word1[0:i-1] word2[0:j-1]替换一个字符)
                    dp[i][j] = min(dp[i-1][j] + 1, min(dp[i][j-1] + 1, dp[i-1][j-1]+1));
                }
            }
        }
        return dp[n][m];
    }
};
// @lc code=end

