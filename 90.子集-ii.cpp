/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> s;
        backtracking(nums, ans, s, 0);
        return ans;
     }

     void backtracking(vector<int>& nums, vector<vector<int>>& ans, vector<int>& s, int i) {
        ans.push_back(s);
        for(int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j-1]) {
                continue;
            }
            s.push_back(nums[i]);
            backtracking(nums, ans, s, j+1);
            s.pop_back();
        }
     }
};
// @lc code=end

