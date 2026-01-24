/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        // 解法1
        // int sum = 0;
        // backtracking(candidates, ans, combine, 0, sum, target);

        // 解法2
        backtracking2(candidates, ans, combine, 0, target);

        return ans;
    }

    void backtracking(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& combine, int index, int sum, int target) {
        if (sum == target) {
            ans.push_back(combine);
        } else if (sum < target) {
            for(int i = index; i < candidates.size(); i++) {
                combine.push_back(candidates[i]);
                sum += candidates[i];
                backtracking(candidates, ans, combine, i, sum, target);
                combine.pop_back();
                sum -= candidates[i];
            }
        }
    }

    void backtracking2(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& combine, int i, int target) {
        if (target == 0) {
            ans.push_back(combine);
        } else if (i < candidates.size()) {
            // 如果元素i 符合条件，就选择
            if(candidates[i] <= target) {
                combine.push_back(candidates[i]);
                backtracking2(candidates, ans, combine, i, target - candidates[i]);
                combine.pop_back();
            }
            // 不选择元素 i
            backtracking2(candidates, ans, combine, i + 1, target);
        }
    }
};
// @lc code=end

