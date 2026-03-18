/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // 单调递减栈
        unordered_map<int, int> hmap; // 用来保存 nums2 中元素的下一个更大元素
        stack<int> st;
        vector<int> ans(nums1.size(), -1);

        for(int i = 0; i < nums2.size(); ++i) {
            while (!st.empty() && st.top() < nums2[i])
            {
                hmap[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }

        for(int i = 0; i < nums1.size(); ++i) {
            if (hmap.find(nums1[i]) != hmap.end()) {
                ans[i] = hmap[nums1[i]];
            }
        }

        return ans;
    }
};
// @lc code=end

