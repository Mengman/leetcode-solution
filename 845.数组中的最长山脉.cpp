/*
 * @lc app=leetcode.cn id=845 lang=cpp
 *
 * [845] 数组中的最长山脉
 */

// @lc code=start
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if (arr.size() < 3) return 0;

        int ans = 0;

        for(int i = 1; i < arr.size() - 1; i++) {
            int l = i, r = i;
            while (true)
            {
                int tmp_l = l, tmp_r = r;
                if (l > 0 && arr[l-1] < arr[l]) tmp_l--;

                if (r < arr.size() - 1 && arr[r] > arr[r+1]) tmp_r++;

                if (tmp_l == l && tmp_r == r) {
                    if (r > l && l != i && r != i) {
                        int length = r - l + 1;
                        if (length > ans) {
                            ans = length;
                        }
                    }
                    break;
                }

                l = tmp_l;
                r = tmp_r;
            }
            
        }

        return ans;
    }
};
// @lc code=end

