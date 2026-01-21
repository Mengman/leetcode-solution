/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2 的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // n & (n-1) 这个操作可以移除二进制 n 最低位的 1
        // 如果 n 是 2 的幂，那么 n & (n-1) == 0
        return n > 0 && (n & (n - 1)) == 0;
    }
};
// @lc code=end

