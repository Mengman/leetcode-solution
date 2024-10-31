/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        if (heights.empty() || heights[0].empty())
        {
            return {};
        }

        vector<vector<int>> ans;
        int m = heights.size(), n = heights[0].size();

        vector<vector<bool>> can_reach_p(m, vector<bool>(n, false));
        vector<vector<bool>> can_reach_a(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i)
        {
            dfs(heights, can_reach_p, i, 0);
            dfs(heights, can_reach_a, i, n - 1);
        }

        for (int i = 0; i < n; ++i)
        {
            dfs(heights, can_reach_p, 0, i);
            dfs(heights, can_reach_a, m - 1, i);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; ++j)
            {
                if (can_reach_p[i][j] && can_reach_a[i][j])
                {
                    ans.push_back(vector<int>{i, j});
                }
            }
        }
        return ans;
    }

    void dfs(const vector<vector<int>> &matrix, vector<vector<bool>> &can_reach, int r, int c)
    {
        if (can_reach[r][c])
        {
            return;
        }

        can_reach[r][c] = true;
        int x, y;
        for (int i = 0; i < 4; ++i)
        {
            x = r + direction[i], y = c + direction[i + 1];
            if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() && matrix[r][c] <= matrix[x][y])
            {
                dfs(matrix, can_reach, x, y);
            }
        }
    }

private:
    vector<int> direction{-1, 0, 1, 0, -1};
};
// @lc code=end
