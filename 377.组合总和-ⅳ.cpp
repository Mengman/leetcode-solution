/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target+1, 0);
        dp[0] = 1;

        for(int i = 1; i <= target; ++i) {
            for(int& num : nums) {
                // 第二个条件 "dp[i - num] <= INT_MAX - dp[i]"
                // 是一个官方取巧的操作，因为组合数目可能很大，导致越界。
                // 但是由于题目说了，结果数不会越界，所以出现越界的情况就直接跳过
                if(i >= num && dp[i - num] <= INT_MAX - dp[i]) {
                    dp[i] += dp[i-num];
                }
            }
        }

        return dp[target];
    }
};
// @lc code=end

