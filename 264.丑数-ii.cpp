/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ans(n+1);
        ans[1] = 1;
        int p2 = 1, p3 = 1, p5 = 1;
        for(int i = 2; i <= n; i++) {
            int a = ans[p2] * 2;
            int b = ans[p3] * 3;
            int c = ans[p5] * 5;

            int min_val = min(a, min(b, c));
            
            if(min_val == a) p2++;
            if(min_val == b) p3++;
            if(min_val == c) p5++; 

            ans[i] = min_val;

        }
        return ans[n];
    }

};
// @lc code=end

