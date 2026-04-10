/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */

// @lc code=start
class Solution
{
public:
    string getPermutation(int n, int k)
    {
        return cantorExpansion(n, k);
    }

    string cantorExpansion(int n, int k)
    {
        vector<int> factorial(n);
        factorial[0] = 1;
        for (int i = 1; i < factorial.size(); ++i)
        {
            factorial[i] = factorial[i - 1] * i;
        }

        --k;
        string ans;
        vector<int> valid(n + 1, 1);

        for (int i = 1; i <= n; ++i)
        {
            int order = k / factorial[n - i] + 1;

            for (int j = 1; j <= n; ++j)
            {
                order -= valid[j];
                if (!order)
                {
                    ans += (j + '0');
                    valid[j] = 0;
                    break;
                }
            }

            k %= factorial[n - i];
        }

        return ans;
    }
};
// @lc code=end
