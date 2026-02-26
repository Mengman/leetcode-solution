/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s = strs.size();
        vector<int> nums0(s, 0);
        vector<int> nums1(s, 0);

        // 统计每个字符串中包含0和1的个数
        for(int i = 0; i < s; ++i) {
            string ss = strs[i];
            for(int j = 0; j < ss.length(); ++j) {
                if(ss[j] == '0') {
                    nums0[i]++;
                } else {
                    nums1[i]++;
                }
            }
        }

        // 记录strs的前i个字符串中使用j个'0'和k个'1'的情况下最多可以得到的字符串数量
        vector<vector<vector<int>>> dp(s+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));

        for(int i = 1; i <= s; ++i) {
            for(int j = 0; j <= m; ++j) {
                for(int k = 0; k <= n; ++k) {
                    // 当前字符串中0的个数大于 j
                    // 或者字符串中1的个数大于 k
                    // 不能选择当前字符
                    if (j < nums0[i-1] || k < nums1[i-1]) {
                        dp[i][j][k] = dp[i-1][j][k]; 
                    } else {
                        dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-nums0[i-1]][k-nums1[i-1]]+1);
                    }
                }
            }
        }

        return dp[s][m][n];
    }
};
// @lc code=end

