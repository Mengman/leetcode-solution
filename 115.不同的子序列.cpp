/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        // 方法一：回溯法 超时
        // return backtrack(s, t);

        return dpSolution(s, t);
    }

    int dpSolution(string& s, string& t) {
        int m = s.length(), n = t.length();
        if (m < n) return 0;

        vector<vector<unsigned long long>> dp(m+1, vector<unsigned long long>(n+1, 0));

        for(int j = 0; j <= n; ++j) dp[m][j] = 0;
        for(int i = 0; i <= m; ++i) dp[i][n] = 1;

        for(int i = m - 1; i >= 0; --i) {
            for(int j = n -1; j >= 0; --j) {
                if (s[i] == t[j]) {
                    dp[i][j] = dp[i+1][j+1] + dp[i+1][j];
                } else {
                    dp[i][j] = dp[i+1][j];
                }
            }
        }
        
        return dp[0][0];
    }

    int backtrack(string& s, string& t) {
        int ans = 0;
        vector<int> path;

        findSubstrNum(s, t, 0, 0, path, ans);

        return ans;
    }

    void findSubstrNum(string& s, string& t, int i, int j, vector<int>& path, int& ans) {
        if (path.size() == t.length()) {
            ans++;
            return;
        }

        for(int k = i; k < s.length(); ++k) {
            if (s[k] != t[j]) continue;
            path.push_back(k);
            findSubstrNum(s, t, k+1, j+1, path, ans);
            path.pop_back();
        }
    }
};
// @lc code=end

