/*
 * @lc app=leetcode.cn id=1524 lang=cpp
 *
 * [1524] 和为奇数的子数组数目
 */

// @lc code=start
class Solution {
const int MOD = 1000000007;
public:
    int numOfSubarrays(vector<int>& arr) {
        // 奇数 + 奇数 = 偶数
        // 偶数 + 偶数 = 偶数
        // 偶数 + 奇数 = 奇数

        int ans = 0;
        int odd = 0, even = 1;
        int subsum = 0;
        for(int i = 0; i < arr.size(); ++i) {
            subsum += arr[i];

            // i 位置前缀和为偶数
            // 则以 i 位置结尾的奇数子数组的个数为 odd 个
            if (subsum % 2 == 0) {
                ans += odd;
                ans %= MOD;
                even++;
            } else {
                // i 位置前缀和为奇数
                // 则以 i 位置结尾的偶数子数组的个数为 even 个
                ans += even;
                ans %= MOD;
                odd++;
            }
        }

        return ans;
    }
};
// @lc code=end

