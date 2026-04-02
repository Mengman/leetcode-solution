/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */

// @lc code=start
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> nums(n, 0);

        for(auto& bk : bookings) {
            nums[bk[0]-1] += bk[2];
            if (bk[1] < n) nums[bk[1]] -= bk[2];
        }

        for(int i = 1; i < nums.size(); ++i) {
            nums[i] += nums[i-1];
        }

        return nums;
    }
};
// @lc code=end

