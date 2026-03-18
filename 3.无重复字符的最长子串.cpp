/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() < 2) return s.length();

        unordered_map<char, int> hmap;
        int ans = 1;
        for(int left=0, right=0; right < s.length(); right++) {
            if (hmap.count(s[right]) && hmap[s[right]] >= left)
            {
                left = hmap[s[right]]+1;
            }
            hmap[s[right]] = right;
            
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end

