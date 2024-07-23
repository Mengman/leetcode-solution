/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> indices;
        vector<int> ans(temperatures.size());

        for(int i = 0; i < temperatures.size(); ++i)
        {
            while (!indices.empty())
            {
                int j = indices.top();
                if (temperatures[i] <= temperatures[j]) {
                    break;
                }
                indices.pop();
                ans[j] = i - j;
            }
            indices.push(i);
        }

        return ans;
    }
};
// @lc code=end

