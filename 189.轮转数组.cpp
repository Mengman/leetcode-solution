/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // 解法1： 使用额外数组 
        // vector<int> tmp(nums.size());
        // for(int i = 0; i < nums.size(); i++) {
        //     tmp[(i + k) % nums.size()] = nums[i];
        // }
        // nums.assign(tmp.begin(), tmp.end());


        // 解法2：三次轮转，空间复杂度 O(1)
        int l = k % nums.size();
        reverse(nums, 0, nums.size() - l - 1);
        reverse(nums, nums.size() - l, nums.size() - 1);
        reverse(nums, 0, nums.size()-1);

    }

    void reverse(vector<int>& nums, int start, int end) {
        while (start < end)
        {
            int tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;
            start++;
            end--;
        }
    }
};
// @lc code=end

