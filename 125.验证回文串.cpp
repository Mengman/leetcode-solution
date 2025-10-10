/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        while(l < r) {
            char left = s[l];
            if ((left >= 'a' && left <= 'z') || (left >= 'A' && left <= 'Z')) {
                if (left >= 'A' && left <= 'Z') {
                    left += 32; 
                }
            } else {
                l += 1;
                continue;
            }
            
            char right = s[r];
            if ((right >= 'a' && right <= 'z') || (right >= 'A' && right <= 'Z')) {
                if (right >= 'A' && right <= 'Z') {
                    right += 32; 
                }
            } else {
                r -= 1;
                continue;
            }

            if (left != right) {
                return false;
            } else {
                l += 1;
                r -= 1;
            }
        }

        return true;
    }
};
// @lc code=end

