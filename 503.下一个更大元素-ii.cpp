/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // 利用单调栈-小顶栈
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n, -1);

        // 将数组前 n-1 个元素加到 nums 数组末尾
        // 实际操作用 i % n 带等效替代
        for(int i = 0; i < 2*n - 1; ++i) {
            while(!st.empty() && nums[st.top()] < nums[i%n]) {
                ans[st.top()] = nums[i%n];
                st.pop();
            }
            st.push(i%n);
        }
        return ans;
    }
};
// @lc code=end

