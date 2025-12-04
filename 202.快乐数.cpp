/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        s.clear();

        while (true)
        {
            int m = 0;
            while (n >= 10)
            {
                int v = n % 10;
                n = n / 10;
                m += v * v;
            }
            m += n * n;
            if (m == 1) {
                return true;
            } else if (s.find(m) != s.end()) {
                return false;
            } else {
                s.insert(m);
            }
            n = m;
            m = 0;
        }
    }
private:
    unordered_set<int> s;
};
// @lc code=end

