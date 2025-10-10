/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 解法1: 整体建表法
        // int k = 0;
        // for(int i = 0; i < nums.size(); i++) {
        //     if (nums[i] != 0) {
        //         nums[k++] = nums[i];
        //     }
        // }
        // for(int j = k; j < nums.size(); j++) {
        //     nums[j] = 0;
        // }

        // 解法2：元素移动发
        int d = 0; // 要删除元素个数
        for(int i =0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                nums[i - d] = nums[i];
            } else {
                d++;
            }
        }

        for(int j = nums.size() - 1; j > nums.size() - 1 - d; j--) {
            nums[j] = 0;
        }

    }
};
// @lc code=end

