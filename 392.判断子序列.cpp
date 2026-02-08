/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length(), n = t.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1));

        int ans = 0;
        for(int i = 1; i < n + 1; ++i) {
            for(int j = 1; j < m + 1; ++j) {
                if (t[i-1] == s[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans == m;
    };

    bool solution1(string s, string t) {
        unordered_map<char, vector<int>> mmap;
        for(int i = 0; i < t.length(); ++i) {
            mmap[t[i]].push_back(i);
        }

        int pos = 0;
        for(int j = 0; j < s.length(); ++j) {
            if(mmap.find(s[j]) == mmap.end()) {
                return false;
            }

            bool matched = false;
            for(int v : mmap[s[j]]) {
                if (pos >= v) {
                    continue;
                } else {
                    pos = v;
                    matched = true;
                    break;
                }
            }

            if (!matched) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

