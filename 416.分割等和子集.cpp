/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0)
            return false;

        int target = sum / 2;
        
        vector<int> dp(target + 1, 0);

        for(int i = 1; i < nums.size() + 1; ++i) {
            for(int w = target; w > nums[i - 1] - 1; --w) {
                dp[w] = max(dp[w], dp[w - nums[i - 1]] + nums[i - 1]);
            }
        }

        return dp[target] == target;
    }
};
// @lc code=end

