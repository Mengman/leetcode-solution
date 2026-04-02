/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */

// @lc code=start
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int maxDist = 0;
        for(auto& trip : trips) {
            maxDist = max(maxDist, trip[2]);
        }

        vector<int> diff(maxDist+1, 0);

        for(auto& trip : trips) {
            diff[trip[1]] += trip[0];
            diff[trip[2]] -= trip[0];
        }

        int count = 0;
        for(int i = 0; i <= maxDist; ++i) {
            count += diff[i];
            if (count > capacity) return false;
        }

        return true;
    }
};
// @lc code=end

