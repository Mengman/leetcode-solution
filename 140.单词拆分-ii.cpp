/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */

// @lc code=start
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // DP + backtrack
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> ans;
        backtrack(s, wordSet, 0, ans);

        return ans[0];
    }

    void backtrack(string& s, unordered_set<string>& wordSet, int i, unordered_map<int, vector<string>>& ans) {
        if (ans.count(i)) {
            return;
        }

        if (i == s.size()) {
            ans[i] = {""};
            return;
        }
        ans[i] = {};
        for(int j = i+1; j <= s.size(); ++j) {
            string word = s.substr(i, j - i);
            if (wordSet.count(word)) {
                backtrack(s, wordSet, j, ans);
                for(const string& succ: ans[j]) {
                    ans[i].push_back(succ.empty() ? word : word + " " + succ);
                }
            }

        }
    }

};
// @lc code=end

