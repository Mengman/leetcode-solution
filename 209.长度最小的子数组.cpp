/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if (nums.size() < 1) return 0;

        int n = nums.size();
        vector<int> presum(n+1, 0);
        presum[0] = 0;
        for(int i = 1; i <= n; i++) {
            presum[i] = nums[i-1] + presum[i-1];
        }

        int ans = n + 1;
        int low = 0, high = 0;
        while (high < n)
        {
            if(presum[high+1] - presum[low] >= target) {
                ans = min(ans, high + 1 - low);
                low++;
            } else {
                high++;
            }
        }

        if (ans == n + 1) {
            return 0;
        } else {
            return ans;
        }


    }
};
// @lc code=end

