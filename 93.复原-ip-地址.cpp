/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string path;
        backtrack(s, 0, 0, path, res);
        return res;
    }

    void backtrack(const string& s, int start, int segment, string& path, vector<string>& res) {
        if (segment == 4 && start == s.size()) {
            res.push_back(path.substr(0, path.size() - 1)); // Remove the last dot
            return;
        }
        if (segment >= 4) return;

        for (int len = 1; len <= 3; ++len) {
            if (start + len > s.size()) break;
            string segmentStr = s.substr(start, len);
            if (isValid(segmentStr)) {
                path += segmentStr + '.';
                backtrack(s, start + len, segment + 1, path, res);
                path.erase(path.size() - len - 1); // Backtrack
            }
        }
    }

    bool isValid(const string& segmentStr) {
        if (segmentStr.size() > 1 && segmentStr[0] == '0') return false; // Leading zero
        int val = stoi(segmentStr);
        return val >= 0 && val <= 255;
    }
};
// @lc code=end

