/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        backtracking(nums, 0, ans, path);
        return ans;
    }

    void backtracking(vector<int>& nums, int index, vector<vector<int>>& ans, vector<int>& path) {
        ans.push_back(path);
        if (index >= nums.size()) {
            return;
        }

        for(int i = index; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1, ans, path);
            path.pop_back();
        }
    }
};
// @lc code=end

