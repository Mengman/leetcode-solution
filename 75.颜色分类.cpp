/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 解法1： 暴力遍历法
        // int k = 0;
        // // 排序红色
        // for(int i = 0; i < nums.size(); i++) {
        //     if(nums[i] == 0) {
        //         nums[i] = nums[k];
        //         nums[k++] = 0;
        //     }
        // }

        // //排序白色
        // for(int i = k; i < nums.size(); i++) {
        //     if(nums[i] == 1) {
        //         nums[i] = nums[k];
        //         nums[k++] = 1;
        //     }
        // }


        // 解法2：区间划分
        int i = 0, j = -1, k = nums.size();
        while (i < k)
        {
            if (nums[i] == 0) {
                j++;
                if (i != j) swap(nums[i], nums[j]);
                i++;
            } else if (nums[i] == 2) {
                k--;
                if (i != k) swap(nums[i], nums[k]);
            } else {
                i++;
            }
        }
    }
};
// @lc code=end

