/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet;
        int maxWordLen = 0;
        for(auto w : wordDict) {
            wordSet.insert(w);
            if (w.length() > maxWordLen) maxWordLen = w.length();
        }

        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for(int i = 0; i <= s.length(); ++i) {
            for(int j = i-1; j >=0 && i - j <= maxWordLen; --j) {
                if (dp[j] && wordSet.find(s.substr(j, i-j)) != wordSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp.back();
    }
};
// @lc code=end

