/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
public:
    NumArray(vector<int>& nums) {
        presum.resize(nums.size() + 1);
        presum[0] = 0;
        for(int i = 1; i < presum.size(); ++i) {
            presum[i] = presum[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return presum[right+1] - presum[left];
    }

private:
    vector<int> presum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

