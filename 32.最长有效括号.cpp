/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ')') {
                if(!st.empty()) st.pop();
                
                if (st.empty()) {
                    st.push(i);
                } else {
                    int tmp = i - st.top();
                    if (tmp > ans) {
                        ans = tmp;
                    }
                }
            
            } else if (s[i] == '(') {
                st.push(i);
            }
        }
        return ans;
    }
};
// @lc code=end

