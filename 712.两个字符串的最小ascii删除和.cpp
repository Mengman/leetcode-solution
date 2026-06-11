/*
 * @lc app=leetcode.cn id=712 lang=cpp
 *
 * [712] 两个字符串的最小ASCII删除和
 */

// @lc code=start
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        int ans = 0;
        if (n1 == 0) {
            for(char c : s2) {
                ans += c;
            }
            return ans;
        }

        if (n2 == 0) {
            for(char c : s1) {
                ans += c;
            }
            return ans;
        }

        // dp[i][j] 代表 s1[0:i-1] 与 s2[0:j-1] 之间相等删除 ASCII 最小值
        vector<vector<int>> dp(n1+1, vector<int>(n2+1));
        dp[0][0] = 0;

        for(int i = 1 ; i <= n1; i++) 
            dp[i][0] = dp[i-1][0] + s1[i-1];
        
        for(int j = 1; j <= n2; j++)
            dp[0][j] = dp[0][j-1] + s2[j-1];

        // 状态转移方程
        // s1[i-1] == s2[j-1]: dp[i][j] = dp[i-1][j-1]
        // s1[i-1] != s2[j-1]: dp[i][j] = min(dp[i-1][j] + s1[i-1], dp[i][j-1] + s2[j-1])

        for(int i = 1; i <= n1; i++) {
            for(int j = 1; j <= n2; j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i-1][j] + s1[i-1], dp[i][j-1] + s2[j-1]);
                }
            }
        }

        return dp[n1][n2];
    }
};
// @lc code=end

