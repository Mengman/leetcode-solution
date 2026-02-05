/*
 * @lc app=leetcode.cn id=1723 lang=cpp
 *
 * [1723] 完成所有工作的最短时间
 */

// @lc code=start
class Solution {
    const int INF = 0x3f3f3f3f;
    int ans = INF;
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.begin(), jobs.end(), greater<int>());

        vector<int> workloads(k, 0);
        backtrack(jobs, workloads, 0, 0);

        return ans;
    }

    void backtrack(vector<int>& jobs, vector<int>& workloads, int idx, int max_work) {
        // 剪枝：当前最大工作时长超过已有方案
        if (max_work >= ans) {
            return;
        }

        // 工作分配完毕
        if (idx == jobs.size()) {
            ans = max_work;
            return;
        }

        for(int i = 0; i < workloads.size(); ++i) {
            workloads[i] += jobs[idx];

            backtrack(jobs, workloads, idx+1, max(max_work, workloads[i]));

            workloads[i] -= jobs[idx];

            // 关键去重剪枝：
            // 如果当前工人分配工作后工作量为0，说明后续空闲工人也无需尝试
            // 因为在当前状态下，分配给任何一个“零工作量”的工人结果都是等价的
            if (workloads[i] == 0) {
                break;
            }
        }
    }
};
// @lc code=end

