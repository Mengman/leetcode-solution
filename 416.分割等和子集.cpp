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
        int n = nums.size();

        if (sum % 2 != 0)
            return false;

        int W = sum / 2;

        int maxV = 0;
        for(int n : nums) {
            if (maxV < n) maxV = n;
        }

        if (maxV > W) return false;
        
        // return solution1(W, nums);


        return solution2(W, nums);
    }


    bool solution1(int W, vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

        for(int i = 1; i < nums.size() + 1; ++i) {
            for(int r = 0; r <= W; ++r) {
                if (r < nums[i-1]) {
                    dp[i][r] = dp[i-1][r];
                } else {
                    dp[i][r] = max(dp[i-1][r], dp[i-1][r-nums[i-1]] + nums[i-1]);
                }
            }
        }

        return dp[n][W] == W;
    }


    bool solution2(int W, vector<int>& nums) {
        vector<int> dp(W+1, 0);
        for(int i = 1; i < nums.size(); ++i) {
            for(int r = W; r >= nums[i-1]; --r) {
                dp[r] = max(dp[r], dp[r-nums[i-1]] + nums[i-1]);
            }
        }

        return dp[W] == W;
    }
};
// @lc code=end

