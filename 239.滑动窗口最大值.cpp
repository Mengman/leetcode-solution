/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        for(int i = 0; i < nums.size(); ++i) {
            // 滑动窗口，移除窗口最左边的值
            if(!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // 将小于新元素的值都移出队列
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            // 新元素始终都会进入队列
            dq.push_back(i);
            // 滑动窗口最大的元素的位置都会保存在队列头
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
// @lc code=end

