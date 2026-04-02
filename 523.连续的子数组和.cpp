/*
 * @lc app=leetcode.cn id=523 lang=cpp
 *
 * [523] 连续的子数组和
 */

// @lc code=start
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        return presumHash(nums, k);
    }

    bool presumSolution(vector<int>& nums, int k) {
        if (nums.size() < 2) {
            return false;
        }
        // 直接使用前缀和数组，超时
        vector<int> presum(nums.size()+1);

        presum[0] = 0;
        for(int i = 1; i < presum.size(); ++i) {
            presum[i] = presum[i-1] + nums[i-1];
            for(int j = i - 2; j >= 0; j--) {
                if ((presum[i] - presum[j]) % k == 0) {
                    return true;
                }
            }
        }

        return false;
    }


    bool presumHash(vector<int>& nums, int k){
        int m = nums.size();
        if (m < 2) {
            return false;
        }

        unordered_map<int, int> mp;
        mp[0] = -1;
        int remainder = 0;
        for(int i = 0; i < m; ++i) {
            remainder = (remainder + nums[i]) % k;
            if (mp.count(remainder)) {
                int prevIndex = mp[remainder];
                if (i - prevIndex >= 2) {
                    return true;
                }
            } else {
                mp[remainder] = i;
            }
        }
        return false;
    }
};
// @lc code=end

