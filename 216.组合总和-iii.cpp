/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> s;
        // backtracking(ans, s, k, n, 1, 0);
        backtrack2(ans, s, k, n, 1);
        return ans;
    }

    // 记录路径
    void backtracking(vector<vector<int>>& ans, vector<int> s, int k, int n, int j, int i) {
        if(i == k && n == 0) {
            ans.push_back(s);
        } else {
            for(int j1 = j; j1 < 10; j1++) {
                s.push_back(j1);
                backtracking(ans, s, k, n - j1, j1 + 1, i + 1);
                s.pop_back();
            }
        }
    }

    // 记录状态
    void backtrack2(vector<vector<int>>& ans, vector<int> s, int k, int n, int i) {
        if(s.size() == k && n == 0) {
            ans.push_back(s);
        } else {
            if (i < 10) {
                // 选择 i
                if (n - i >= 0) {
                    s.push_back(i);
                    backtrack2(ans, s, k, n - i, i+1);
                    s.pop_back();
                }
                
                // 不选择 i
                backtrack2(ans, s, k, n, i+1);
            }
        }
    }
};
// @lc code=end

