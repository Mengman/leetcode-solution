/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * [646] 最长数对链
 */

// @lc code=start
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        if (n < 2) return 1;

        sort(pairs.begin(), pairs.end(), [](const vector<int>&a, const vector<int>& b) {
            return a[1] < b[1];
        });

        vector<int> dp(n, 1);
        int ans = 0;
        for(int i = 1; i < n; ++i) {

            for (int j = 0; j < i; ++j) {
                if(pairs[i][0] > pairs[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
// @lc code=end

