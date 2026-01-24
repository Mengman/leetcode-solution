/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 非递减子序列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> s;
        backtracking(nums, ans, s, 0);
        return ans;
    }

    void backtracking(vector<int>& nums, vector<vector<int>>& ans, vector<int>& s, int i) {
        if(s.size() > 1) {
            ans.push_back(s);
        }

        unordered_set<int> used;
        for(int j = i; j < nums.size(); j++) {
            if (!s.empty() && nums[j] < s.back()) continue;
            if (used.count(nums[j]) == 1) continue;

            used.insert(nums[j]);
            s.push_back(nums[j]);
            backtracking(nums, ans, s, j + 1);
            s.pop_back();
        }
    }
};
// @lc code=end

