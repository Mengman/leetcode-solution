/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution
{
public:
    string simplifyPath(string path)
    {
        stack<string> st;
        vector<string> parts;
        size_t start = 0;
        size_t end = path.find('/');

        while (end != string::npos)
        {
            if (end > start)
            {
                parts.push_back(path.substr(start, end - start));
            }
            start = end + 1;
            end = path.find('/', start);
        }

        if (start < path.size())
        {
            parts.push_back(path.substr(start));
        }

        for (string p : parts)
        {
            if (p == ".")
            {
                continue;
            }
            else if (p == "..")
            {
                if(!st.empty()) st.pop();
            }
            else
            {
                st.push('/' + p);
            }
        }

        if (st.empty())
        {
            return "/";
        }
        else
        {
            string ans;
            while (!st.empty())
            {
                ans = st.top() + ans;
                st.pop();
            }
            return ans;
        }
    }
};
// @lc code=end
