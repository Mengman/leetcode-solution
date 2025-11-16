/*
 * @lc app=leetcode.cn id=1200 lang=cpp
 *
 * [1200] 最小绝对差
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int minDiff = arr[arr.size()-1] - arr[0];
        vector<vector<int>> ans;
        for(int i = 0; i < arr.size()-1; i++) {
            int diff = arr[i+1] - arr[i];
            if(diff < minDiff) {
                minDiff = diff;
                ans.clear();
                ans.push_back({arr[i], arr[i+1]});
            } else if (diff == minDiff) {
                ans.push_back({arr[i], arr[i+1]});
            }
        }
        return ans;
    }
};
// @lc code=end

