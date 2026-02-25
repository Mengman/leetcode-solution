/*
 * @lc app=leetcode.cn id=639 lang=cpp
 *
 * [639] 解码方法 II
 */

// @lc code=start
class Solution {
public:
    const int MOD = 1e9 + 7;
    int numDecodings(string s) {
        int n = s.size();
        vector<long long> dp(n+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; ++i) {
            // 将 s[i-1] 解码为一个字母
            if(s[i-1] == '*') {
                dp[i] = (dp[i-1] * 9) % MOD;
            } else if (s[i-1] != '0') {
                dp[i] = dp[i-1];
            } else {
                dp[i] = 0;
            }

            // 将 s[i-2]s[i-1] 一起解码为一个字母
            if(i > 1 && s[i-2] != '0') {
                if(s[i-2] != '*') {
                    if(s[i-1] != '*') {
                    // 数字 + 数字
                        if ((s[i-2] - '0') * 10 + (s[i-1] - '0') <= 26) {
                            dp[i] = (dp[i] + dp[i-2]) % MOD;
                        }

                    } else {
                    // (1~2) + *
                        if (s[i-2] == '1') {
                            // 1+(1~9) 9
                            dp[i] =(dp[i] + dp[i-2] * 9) % MOD;
                        } else if (s[i-2] == '2') {
                            // 2+(1~6) 6
                            dp[i] = (dp[i] + dp[i-2] * 6) % MOD;
                        }
                    }

                } else {
                    if(s[i-1] != '*') {
                    // * + 数字
                        if(s[i-1] - '0' <= 6) {
                            // 1+数字
                            // 2+数字
                            dp[i] = (dp[i] + dp[i-2] * 2) % MOD;
                        } else {
                            // 1+数字 
                            dp[i] = (dp[i] + dp[i-2]) % MOD;
                        }
                    } else {
                    // * + *
                        dp[i] = (dp[i] + dp[i-2] * (9 + 6)) % MOD;
                    }
                }
            }
        }

        return (int)dp[n];

    }
};
// @lc code=end

