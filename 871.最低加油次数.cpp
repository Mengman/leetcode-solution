/*
 * @lc app=leetcode.cn id=871 lang=cpp
 *
 * [871] 最低加油次数
 */

// @lc code=start
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // 如果 startFuel 充足，就不用加油
        if (startFuel >= target) return 0;

        return dp2D(target, startFuel, stations);

        // return dp1D(target, startFuel, stations);
    }

    int dp2D(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        // dp[i][j] 在路过前 i 个加油站，加了 j 次油，可以行驶的最大里程。
        vector<vector<long>> dp(n+1, vector<long>(n+1, 0));
        dp[0][0] = startFuel;
        // 状态转移方程
        // 当 j > i 时，现实中不存在这种情况，所以 dp[i][j] = 0
        // 前 j-1 次加油无法到达加油站 i-1:
        //      dp[i][j] = dp[i-1][j] 如果 dp[i-1][j-1] < stations[i-1][0]
        // 可以到达加油站 i-1：
        //      dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + stations[i-1][1])

        for(int i = 1; i <= n; ++i) {
            dp[i][0] = startFuel;
            // 经过 i 个加油站，最多加 i 次油
            for(int j = 1; j <= i; ++j) {
                if (dp[i-1][j-1] < stations[i-1][0]) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + stations[i-1][1]);
                }
            }
        }

        int ans = n+1;
        for(int i = 0; i <= n; ++i) {
            for(int j = 0; j <= n; ++j) {
                if (dp[i][j] >= target) ans = min(ans, j);
            }
        }

        return ans == n+1 ?  -1 : ans;
    }

    int dp1D(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();

        // dp[i] 表示加 i 次油，最大行驶里程
        vector<long> dp(n + 1);
        dp[0] = startFuel;

        for(int i = 1; i <= n; ++i) {
            for(int j = i; j >= 0; --j) {
                // 加 j 次油后，可以行驶到加油站 i
                if(dp[j] >= stations[i-1][0]) {
                    dp[j+1] = max(dp[j+1], dp[j] + stations[i-1][1]);
                }
            }
        }

        for (int i = 0; i <= n; i++) {
            if (dp[i] >= target) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

