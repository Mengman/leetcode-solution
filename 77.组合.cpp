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
        // 解法1：回溯法，状态记录
        backtracking1(1, 0, n, k, path, ans);

        // 解法2：回溯法，路径记录
        // backtracking2(1, 0, n, k, path, ans);
        return ans;
    }

    void backtracking1(int idx, int depth, int n, int k, vector<int>& path, vector<vector<int>>& ans) {
        if(depth == k) {
            if (path.size() == k) {
                ans.push_back(path);
            }
        } else if (idx <= n) {
            path.push_back(idx);
            backtracking1(idx+1, depth+1, n, k, path, ans);
            path.pop_back();
            backtracking1(idx+1, depth, n, k, path, ans);
        }
    }


    void backtracking2(int idx, int depth, int n, int k, vector<int>& path, vector<vector<int>>& ans) {
        if (depth == k) {
            if (path.size() == k) {
                ans.push_back(path);
            }
        } else {
            for(int j = idx; j <= n; j++) {
                path.push_back(j);
                backtracking2(j+1, depth+1, n, k, path, ans);
                path.pop_back();
            }
        }
    }
};
// @lc code=end

