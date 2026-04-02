/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除了自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // return prefixSuffix(nums);

        return noExtraSpace(nums);
    }

    vector<int> prefixSuffix(vector<int>& nums) {
        vector<int> prefix(nums.size()+1, 1);
        vector<int> suffix(nums.size()+1, 1);

        for(int i = 1; i < prefix.size(); ++i) {
            prefix[i] = prefix[i-1] * nums[i-1];
            suffix[suffix.size() - i - 1] = suffix[suffix.size() - i] * nums[nums.size() - i];
        }

        vector<int> ans(nums.size());
        for(int i = 0; i < ans.size(); ++i) {
            ans[i] = prefix[i] * suffix[i+1];
        }

        return ans;
    }

    vector<int> noExtraSpace(vector<int>& nums) {
        vector<int> ans(nums.size());
        ans[0] = nums[0];

        for(int i = 1; i < nums.size(); ++i) {
            ans[i] = ans[i-1] * nums[i];
        }

        int rightProduct = 1;
        for(int i = ans.size() - 1; i > 0; --i) {
            ans[i] = ans[i-1] * rightProduct;
            rightProduct *= nums[i];
        }

        ans[0] = rightProduct;

        return ans;
    }
};
// @lc code=end

