/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        return bruteForce(s);

        // return dpSolution(s);
    }

    string bruteForce(string &s)
    {
        int n = s.size();
        // 暴力解法
        int plen = 0;
        int pb = 0;
        for (int i = 0; i < n; i++)
        {

            if (i < n - 1 && s[i] == s[i + 1])
            {
                // 检查是不是 aa 型
                int b = i, e = i + 1;
                while (b > 0 && e < n - 1)
                {
                    if (s[b - 1] == s[e + 1])
                    {
                        b--;
                        e++;
                    }
                    else
                    {
                        break;
                    }
                }

                if (e - b + 1 > plen)
                {
                    plen = e - b + 1;
                    pb = b;
                }
            }
            if (0 < i && i < n - 1)
            {
                // 检查是不是 bab 型
                if (s[i - 1] == s[i + 1])
                {
                    int b = i - 1, e = i + 1;
                    while (b > 0 && e < n - 1)
                    {
                        if (s[b - 1] == s[e + 1])
                        {
                            b--;
                            e++;
                        }
                        else
                        {
                            break;
                        }
                    }

                    if (e - b + 1 > plen)
                    {
                        pb = b;
                        plen = e - b + 1;
                    }
                }
            }
            else
            {
                if (1 > plen)
                {
                    plen = 1;
                    pb = i;
                }
            }
        }

        return s.substr(pb, plen);
    }

    string dpSolution(string &s)
    {
        // 动态规划版本
        int n = s.size();
        if (n < 2)
            return s;

        int maxLen = 1;
        int begin = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++)
        {
            // 单字符是回文: dp[i][i] = true
            dp[i][i] = true;
        }

        for (int L = 2; L <= n; L++)
        {
            for (int i = 0; i < n; i++)
            {
                int j = L + i - 1;
                if (j >= n)
                {
                    break;
                }

                if (s[i] != s[j])
                {
                    dp[i][j] = false;
                }
                else
                {
                    if (j - i < 3)
                    {
                        // aa型回文
                        dp[i][j] = true;
                    }
                    else
                    {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                if (dp[i][j] && j - i + 1 > maxLen)
                {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};
// @lc code=end
