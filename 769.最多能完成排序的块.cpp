/*
 * @lc app=leetcode.cn id=769 lang=cpp
 *
 * [769] 最多能完成排序的块
 */

// @lc code=start
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if (arr.size() == 0)
            return 0;
        
        int max_val = arr[0];
        int res = 0;
        for (int i = 0; i < arr.size(); ++i) 
        {
            if (arr[i] > max_val)
                max_val = arr[i];

            if (max_val == i) {
                ++res;
            }
        }
        return res;
    }
};
// @lc code=end

