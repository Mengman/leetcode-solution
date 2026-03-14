/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> numsSorted = nums;
        sort(numsSorted.begin(), numsSorted.end());
        vector<int> ans(n);
        
        for(int i = 0; i < n; ++i) {
            int v = nums[i];
            int j = 0;

            while(j <= n) {
                if (j == n) {
                    ans[i] = -1;
                    break;
                } else if (v >= numsSorted[j]) {
                    j++;
                } else {
                    ans[i] = numsSorted[j];
                    break;
                }
            }
        }

        return ans;

    }
};
// @lc code=end

