/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for(int n : nums) {
            strs.push_back(to_string(n));
        }

        sort(strs.begin(), strs.end(), [](const string& a, const string& b){
            // 这里的比较逻辑是：如果 a+b > b+a，则 a 排在 b 前面
            return a + b > b + a;
        });
        
        // 处理特殊情况：如果排序后最大的数是 "0"，说明整个数组全是 0
        if (strs[0] == "0") {
            return "0";
        }

        string ans = "";
        for(string s : strs) {
            ans += s;
        }

        return ans;
    }
};
// @lc code=end

