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

        // return dfs(0, 0, nums);

        // return knap_dp_2d(nums, target);

        return knap_dp_1d(nums, target);
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

    int knap_dp_2d(vector<int> &nums, int target) {
        /*
        把问题转换为 0/1 背包问题
        设 nums 所有元素的和为 sum
        nums 中所有被设置为 + 的数字的和为 pos
        所有被设置为 - 的数字的和为 neg
        则有 pos + neg = target (1)
        同时 pos + (-neg) = sum (2)
        neg = target - pos  (3)
        将 3 带入 2 式
        pos - target + pos = sum
        2pos = sum + target
        pos = (sum + target) / 2

        所以只需要找到 nums 中一部分的元素和等于 (sum + target) /2 方案的个数就得到答案
         */
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        if ((target + sum) % 2 != 0 || abs(target) > sum) return 0;
        
        int W = (target + sum) / 2;

        // dp 用来计算：从(0, i-1)元素中，选取元素和为 r 的方法数
        vector<vector<int>> dp(n + 1, vector<int>(W+1, 0));
        // 前零个元素和为0的方法有一种
        dp[0][0] = 1;

        for(int i = 1; i <= n; ++i) {
            for(int r = 0; r <= W; ++r) {
                // 不选第 i 个元素
                dp[i][r] = dp[i-1][r];

                // 选择第 i 个元素
                // 方法的总数是 不选时的方法数 + 前i-1个元素和为j-num的方法数
                if (r >= nums[i-1]) {
                   dp[i][r] += dp[i-1][r-nums[i-1]];
                }
            }
        }

        return dp[n][W];
    }

    int knap_dp_1d(vector<int> &nums, int target) {
        /*
        动态规划优化版本，使用1维数组
        */
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        if ((target + sum) % 2 != 0 || abs(target) > sum) return 0;
        
        int W = (target + sum) / 2;

        vector<int> dp(W+1, 0);
        dp[0] = 1;
        for(int num: nums) {
            for(int r = W; r >= num; --r) {
                dp[r] += dp[r - num];
            }
        }

        return dp[W];
    }

private:
    std::map<std::pair<int, int>, int> table;
    int size;
    int tgt;
};
// @lc code=end
