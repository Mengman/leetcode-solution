/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        size = nums.size();
        tgt = target;

        return dfs(0, 0, nums);
    }

    int dfs(int i, int cur_sum, vector<int> &nums)
    {
        if (i == size)
        {
            if (cur_sum == tgt)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        std::pair<int, int> key = std::make_pair(i, cur_sum);
        if (table.find(key) != table.end())
        {
            return table[key];
        }

        int cnt = dfs(i + 1, cur_sum - nums[i], nums) + dfs(i + 1, cur_sum + nums[i], nums);
        table[key] = cnt;
        return cnt;
    }

private:
    std::map<std::pair<int, int>, int> table;
    int size;
    int tgt;
};
// @lc code=end
