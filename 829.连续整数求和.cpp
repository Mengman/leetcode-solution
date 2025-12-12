/*
 * @lc app=leetcode.cn id=829 lang=cpp
 *
 * [829] 连续整数求和
 */

// @lc code=start
class Solution {
public:
    int consecutiveNumbersSum(int n) {
        /*
        * 设有连续k个数相加等于n
        * x + (x+1) + ... + (x+k-1) = n
        * -> [k(2x + k - 1)] / 2 = n
        * x 最小值是 1 -> k(k+1) <= 2n
        * 穷举检查满足 k(k+1) <= 2n 的 k
        * 
        * 当 k 为奇数时：
        * (2x+k-1) 是偶数 -> (2x + k - 1) / 2 = n / k
        * n % k == 0; k 可以被 n 整除
        * 
        * 当 k 为偶数时：
        * (2x+k-1) 是奇数 
        * -> (2x + k - 1) / 2 = n / k 是小数, k 不能被 n 整除
        * -> (2x + k - 1) = 2n / k 是整数，k 可以被 2n 整除
        * n % k != 0 && 2n % k == 0
        */
        int ans = 0;
        for (int k = 1; k * (k + 1) <= 2 * n; k++) {
            if(judge(n, k)) ans++;
        }
        return ans;
    }

    bool judge(int n, int k) {
        if(k % 2 == 1) {
            // k 为奇数
            return n % k == 0;
        } else {
            // k 为偶数
            return n % k != 0 && 2*n % k == 0;
        }
    }
};
// @lc code=end

