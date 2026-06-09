/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int n2 = 0;
        int n1 = 1;
        int ans = 0;
        for(int i = 2; i < n+1; i++) {
            ans = n1 + n2;
            n2 = n1;
            n1 = ans;
        }

        return ans;
    }
};
// @lc code=end

