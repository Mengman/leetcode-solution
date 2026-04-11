/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        backtrack_dfs(s, ans, path, 0);

        return ans;
    }

    void backtrack_dfs(string& s, vector<vector<string>>& ans, vector<string>& path, int i) {
        if (i == s.length()) {
            ans.push_back(path);
            return;
        }
        
        for(int j=i; j < s.length(); ++j) {
            if (isPalindrome(s, i, j)) {
                path.push_back(s.substr(i, j - i + 1));
                backtrack_dfs(s, ans, path, j+1);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string&s, int begin, int end) {
        while(begin < end) {
            if (s[begin] != s[end]) {
                return false;
            } else {
                begin++;
                end--;
            }
        }
        return true;
    }
};
// @lc code=end

