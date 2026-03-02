/*
 * @lc app=leetcode.cn id=2895 lang=cpp
 *
 * [2895] 最小处理时间
 */

// @lc code=start
class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(tasks.begin(), tasks.end());
        sort(processorTime.begin(), processorTime.end());
        int n = processorTime.size();
        int ans = 0;
        // 贪心算法
        // 每次开始最早的CPU执行时间最长的任务
        // 依次迭代
        for(int i = 0; i < n; ++i) {
            ans = max(ans, processorTime[i] + tasks[(n-i)*4 - 1]);
        }

        return ans;
    }
};
// @lc code=end

