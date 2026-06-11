/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 将任意元素先设置为答案，并且设置计数为 1
        // 遇到相同的元素计数+1，否者-1
        // hp 减到 0 时，换另外一个元素，执行相同的操作。
        int ans = 0, hp = 0;
        for(int n : nums) {
            if (hp == 0) {
                ans = n;
                hp = 1;
            } else {
                hp += n == ans ? 1 : -1;
            }
        }

        return ans;
    }
};
// @lc code=end

