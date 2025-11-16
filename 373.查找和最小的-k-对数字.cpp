/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的 K 对数字
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<vector<int>> ans;
        if (nums1.empty() || nums2.empty() || k <= 0)
            return ans;

        // 最小堆: 存(nums1[i]+nums2[j], i, j)
        using T = tuple<int, int, int>;
        auto cmp = [](const T &a, const T &b)
        {
            return get<0>(a) > get<0>(b);
        };

        priority_queue<T, vector<T>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < nums1.size() && i < k; ++i)
        {
            pq.emplace(nums1[i] + nums2[0], i, 0);
        }

        while (k-- > 0 && !pq.empty())
        {
            auto [sum, i, j] = pq.top();
            pq.pop();
            ans.push_back({nums1[i], nums2[j]});

            if (j + 1 < nums2.size())
            {
                pq.emplace(nums1[i] + nums2[j+1], i, j+1);
            }
        }

        return ans;
    }
};
// @lc code=end
