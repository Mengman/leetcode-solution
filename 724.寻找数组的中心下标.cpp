/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> presum(nums.size()+1, 0);

        for(int i = 0; i < nums.size(); ++i) {
            presum[i+1] = presum[i] + nums[i];
        }

        int ans = -1;
        int n = presum.size() - 1;
        for(int i = 1; i < presum.size(); ++i) {
            if (presum[i-1] == presum[n] - presum[i]) {
                ans = i - 1;
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

