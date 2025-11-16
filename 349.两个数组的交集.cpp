/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        // 方法一： 使用 HashSet
        // unordered_set<int> s1(nums1.begin(), nums1.end());
        // unordered_set<int> result;

        // for(int n : nums2) {
        //     if(s1.count(n)) {
        //         result.insert(n);
        //     }
        // }

        // return vector<int>(result.begin(), result.end());

        // 方法二：使用 HashMap
        // unordered_map<int, int> map1;
        // for(int n : nums1) {
        //     if(map1.find(n) == map1.end()) {
        //         map1[n] = 1;
        //     }
        // }

        // for(int n : nums2) {
        //     if(map1.find(n) != map1.end()) {
        //         map1[n]++;
        //     }
        // }

        // vector<int> result;
        // for(auto it : map1) {
        //     if(it.second > 1) {
        //         result.push_back(it.first);
        //     }
        // }

        // return result;


        // 方法三: 排序 + 二路归并
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> ans;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                if (ans.empty() || nums1[i] != ans.back()) {
                    ans.push_back(nums1[i]);
                }
                i++;
                j++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                i++;
            }
        }
        
        return ans;
    }
};
// @lc code=end
