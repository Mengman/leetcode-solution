/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> presum(nums.size()+1);

        presum[0] = 0;
        int ans = 0;
        for(int i = 1; i < presum.size(); ++i) {
            presum[i] = presum[i-1] + nums[i-1];

            for(int j = i-1; j >= 0; --j) {
                if (presum[i] - presum[j] == k) ans++;
            }
        }

        return ans;
    }
};
// @lc code=end

