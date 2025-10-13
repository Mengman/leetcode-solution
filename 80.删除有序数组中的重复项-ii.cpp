/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3) {
            return nums.size();
        }
        // 解法1：整体建表
        // int k = 1;
        // for(int i = 2; i < nums.size(); i++) {
        //     if(nums[i] != nums[k] || nums[k] != nums[k-1]) {
        //         nums[++k] = nums[i];
        //     }
        // }
        // return k + 1;

        // 解法2：删除重复元素
        int k = 0; // 被删除元素个数
        for(int i = 2; i < nums.size(); i++) {
            if(nums[i] == nums[i-k-1] && nums[i] == nums[i-k-2]) {
                k++;
            } else {
                nums[i-k] = nums[i];
            }
        }
        return nums.size() -k ;
    }
};
// @lc code=end

