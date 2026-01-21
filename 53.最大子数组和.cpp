/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 解法：Kadane 算法
        // 维护一个最大前缀和
        int cur = nums[0];
        int ans = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            cur = max(nums[i], nums[i]+cur);
            ans = max(ans, cur);
        }
        return ans;
    }
};
// @lc code=end

