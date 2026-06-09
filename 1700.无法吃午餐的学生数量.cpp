/*
 * @lc app=leetcode.cn id=1700 lang=cpp
 *
 * [1700] 无法吃午餐的学生数量
 */

// @lc code=start
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> qu;
        for(auto s: students) {
            qu.push(s);
        }
        int i = 0;
        int cnt = 0;
        while(!qu.empty()) {
            if (cnt == qu.size()) return qu.size();
            if (qu.front() == sandwiches[i]) {
                qu.pop();
                i++;
                cnt = 0;
            } else {
                int tmp = qu.front();
                qu.pop();
                qu.push(tmp);
                cnt++;
            }
        }
        return 0;
    }
};
// @lc code=end

