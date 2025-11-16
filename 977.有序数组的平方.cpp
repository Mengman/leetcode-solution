/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] *= nums[i];
        }

        int min_val = nums[0], min_idx = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (min_val > nums[i])
            {
                min_val = nums[i];
                min_idx = i;
            }
        }

        ans.push_back(min_val);
        int l = min_idx - 1, r = min_idx + 1;
        while (l >= 0 && r < nums.size())
        {
            if (nums[l] < nums[r])
            {
                ans.push_back(nums[l--]);
            } else if (nums[l] > nums[r]) {
                ans.push_back(nums[r++]);
            } else {
                ans.push_back(nums[l--]);
                ans.push_back(nums[r++]);
            }
        }

        while(l >= 0) {
            ans.push_back(nums[l--]);
        }

        while (r < nums.size())
        {
            ans.push_back(nums[r++]);
        }
        
        return ans;
    }
};
// @lc code=end
