/*
 * @lc app=leetcode.cn id=1287 lang=cpp
 *
 * [1287] 有序数组中出现次数超过25%的元素
 */

// @lc code=start
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        float minCount = arr.size() / 4.0;
        float k = 1.0;
        for(int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i-1]) {
                k++;
                if (k > minCount) {
                    return arr[i];
                }
            } else {
                k = 1;
            }
        }
        return arr[0];
    }
        
};
// @lc code=end

