/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续 1 的个数
 */

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                cnt++;
            } else {
                if (cnt > ans) {
                    ans = cnt;
                }
                cnt = 0;
            }
        }

        if (cnt > ans) {
            ans = cnt;
        }
        return ans;
    }
};
// @lc code=end

