/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */

// @lc code=start
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        // 解法和 300 相似
        int n = nums.size();
        if (n < 2) return n;

        // dp[i]: nums[i] 位置的最长子序列长度
        vector<int> dp(n, 1);
        // dpCount[i]: nums[i] 子序列路径个数
        vector<int> dpCount(n, 1);
        int maxLen = 0;
        for(int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        dpCount[i] = dpCount[j];
                    } else if (dp[j]+1 == dp[i]) {
                        dpCount[i] += dpCount[j];
                    }
                }
            }
            maxLen = max(dp[i], maxLen);
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            if (dp[i] == maxLen) ans += dpCount[i];
        }
        return ans;
    }
};
// @lc code=end

