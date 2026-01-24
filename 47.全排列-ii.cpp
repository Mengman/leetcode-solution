/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        backtracking(nums, ans, 0);
        return ans;
    }

    void backtracking(vector<int>& nums, vector<vector<int>>& ans, int level){
        if (level >= nums.size()) {
            ans.push_back(nums);
        } else {
            for(int i = level; i < nums.size(); ++i) {
                if(judge(nums, level, i)) continue;
                
                swap(nums[level], nums[i]);
                backtracking(nums, ans, level + 1);
                swap(nums[i], nums[level]);
            }
        }
    }


    bool judge(const vector<int>& nums, int m, int n) {
        if(n > m) {
            for(int k = m; k < n; ++k) {
                if (nums[k] == nums[n]) return true;
            }
        }
        return false;
    }
};
// @lc code=end

