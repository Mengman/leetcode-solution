/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 *
 * [1035] 不相交的线
 */

// @lc code=start
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        // 求 nums1 和 nums2 的最长公共子序列
        int n1 = nums1.size();
        int n2 = nums2.size();

        // dp[i][j] nums1[0:i-1] nums2[0:j-1] 的最大公共子序列
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        // 状态转移方程
        // nums1[i] == nums2[j]: dp[i][j] = dp[i-1][j-1] + 1
        // nums1[i] != nums2[j]: dp[i][j] == max(dp[i-1][j], dp[i][j-1])
        

        for(int i = 1; i <= n1; i++) {
            for(int j = 1; j <= n2; j++) {
                if (nums1[i-1] == nums2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n1][n2];
    }
};
// @lc code=end

