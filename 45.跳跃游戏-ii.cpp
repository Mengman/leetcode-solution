/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
    const int MAX = 0x3f3f3f3f;
public:
    int jump(vector<int>& nums) {
        return solution_dp(nums);
    }

    int solution_dp(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, MAX);
        dp[0] = 0;
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[j] >= i - j) {
                    dp[i] = min(dp[i], dp[j]+1);
                }
            }
        }

        return dp[n-1];
    }
};
// @lc code=end

