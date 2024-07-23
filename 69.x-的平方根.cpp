/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        long v = x;
        while (v * v > x)
        {
            v = (v + x / v) / 2;
        }
        return v;
    }
};
// @lc code=end

