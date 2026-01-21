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
        // 解法1：回溯法，状态记录
        // backtracking1(nums, ans, path, 0);

        // 解法2：回溯法，路径记录
        backtracking2(nums, ans, path, 0);
        return ans;
    }

    void backtracking1(vector<int>& nums, vector<vector<int>>& ans, vector<int>& path, int i) {
        if (i >= nums.size()) {
            ans.push_back(path);
        } else {
            path.push_back(nums[i]);
            backtracking1(nums, ans, path, i+1);
            path.pop_back();
            backtracking1(nums, ans, path, i+1);
        }
    }


    void backtracking2(vector<int>& nums, vector<vector<int>>& ans, vector<int>& path, int i) {
        ans.push_back(path);

        for(int k = i; k < nums.size(); k++) {
            path.push_back(nums[k]);
            backtracking2(nums, ans, path, k+1);
            path.pop_back();
        }
    }

};
// @lc code=end

