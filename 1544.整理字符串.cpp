/*
 * @lc app=leetcode.cn id=1544 lang=cpp
 *
 * [1544] 整理字符串
 */

// @lc code=start
class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        int n = s.size();

        for(int i =0; i < n; i++) {
            if (st.empty()) {
                st.push(s[i]);
            } else {
                if (st.top() + 32== s[i] || st.top() - 32== s[i]) {
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }
        }

        string ans = "";
        while (!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
// @lc code=end

