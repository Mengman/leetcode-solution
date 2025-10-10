/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        for(int i =0; i < s.length(); ++i)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                data.push(s[i]);
            } 
            else {
                if (data.empty()) {
                    return false;
                }

                if (match(s[i], data.top())) {
                    data.pop();
                } else {
                   return false;
                }
            }
        }

        return data.empty();
    }
private:
    stack<char> data;
    unordered_set<char> p1 = {'(', ')'};
    unordered_set<char> p2 = {'[', ']'};
    unordered_set<char> p3 = {'{', '}'};

    bool match(char a, char b) {
        if (a == b) {
            return false;
        }

        if (p1.find(a) != p1.end() && p1.find(b) != p1.end()) {
            return true;
        } else if (p2.find(a) != p2.end() && p2.find(b) != p2.end()) {
            return true;
        } else if (p3.find(a) != p3.end() && p3.find(b) != p3.end()) {
            return true;
        } else {
            return false;
        }
    }

};
// @lc code=end

