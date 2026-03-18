/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> hmap;
        int maxN = 0;
        for(char c : s) {
            hmap[c]++;
            maxN = max(maxN, hmap[c]);
        }

        vector<string> buckets(maxN + 1);
        for (auto &[ch, num] : hmap) {
            buckets[num].push_back(ch);
        }

        string res;
        for(int i = maxN; i > 0; i--) {
            string& bucket = buckets[i];
            for(auto &ch : bucket) {
                for(int k = 0; k < i; ++k) {
                    res.push_back(ch);
                }
            }
        }

        return res;
    }
};
// @lc code=end

