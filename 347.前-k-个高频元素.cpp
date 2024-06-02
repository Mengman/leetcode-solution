/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        int max_count = 0;
        for(const int & num: nums) {
            max_count = max(max_count, ++counts[num]);
        }

        vector<vector<int>> buckets(max_count + 1);
        for(const auto &p : counts) {
            buckets[p.second].push_back(p.first);
        }

        vector<int> ans;
        for(int i = max_count; i >= 0 && ans.size() < k; --i) {
            for(const int &num : buckets[i]) {
                ans.push_back(num);
                if(ans.size() == k) {
                    break;
                }
            }
        }
        return ans;
    }

    vector<int> topKFrequent2(vector<int>& nums, int k) {
        unordered_map<int, int> word_count;

        for (int n : nums) {
            ++word_count[n];
        }

        vector<int> result(k, 0);
        vector<int> times(k, 0);
        for (const auto &p : word_count) {
            for (int i = 0; i < times.size(); i++) {
                if (p.second > times[i]) {
                    if (i != k-1) {
                        for(int j = k - 1; j > i; j--) {
                            result[j] = result[j-1];
                            times[j] =  times[j-1];
                        }
                    }
                    result[i] = p.first;
                    times[i] = p.second;
                    break;
                }
            }
        }
        return result;
    }
};
// @lc code=end

