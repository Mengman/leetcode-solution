/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;

        for(int i = 0; i < heights.size(); i++) {
            int localMax = heights[i];
            int minVal = heights[i];
            for(int j = i + 1; j < heights.size(); j++) {
                if(heights[j] < minVal) {
                    minVal = heights[j];
                }

                int area = (j - i + 1) * minVal;
                if(area > localMax) {
                    localMax = area;
                } 
            }
            if(localMax > maxArea) {
                maxArea = localMax;
            }
        }

        return maxArea;
    }
};
// @lc code=end

