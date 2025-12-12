/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;
        backtracking(1, 0, n, k, path, ans);
        return ans;
    }

    void backtracking(int idx, int depth, int n, int k, vector<int>& path, vector<vector<int>>& ans) {
        if(depth == k) {
            ans.push_back(path);
            return;
        }

        for(int i = idx; i < n+1; i++) {
            path.push_back(i);
            backtracking(i+1, depth+1, n, k, path, ans);
            path.pop_back();
        }
    }
};
// @lc code=end

