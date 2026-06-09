/*
 * @lc app=leetcode.cn id=1137 lang=cpp
 *
 * [1137] 第 N 个泰波那契数
 */

// @lc code=start
class Solution {
public:
    int tribonacci(int n) {
        int t0 = 0, t1 = 1, t2 = 1;

        if (n == 0) return t0;
        if (n == 1) return t1;
        if (n == 2) return t2;

        int ans = 0;
        for (int i = 3; i < n+1; i++) {
            ans = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = ans;
        }

        return ans;
    }
};
// @lc code=end

