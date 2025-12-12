/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mapping = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };

        vector<string> result;
        string path;


        function<void(int)> dfs = [&](int idx) {
            if (idx == digits.size()) {
                result.push_back(path);
                return;
            }

            int d = digits[idx] - '0';
            for(char ch : mapping[d]) {
                path.push_back(ch);
                dfs(idx + 1);
                path.pop_back();
            }
        };

        dfs(0);
        return result;
    }
};
// @lc code=end

