/*
 * @lc app=leetcode.cn id=827 lang=cpp
 *
 * [827] 最大人工岛
 */

// @lc code=start
class UnoinFind
{
public:
    UnoinFind(vector<vector<int>> &grid)
    {
        row = grid.size();
        col = grid[0].size();

        parent = vector<int>(row * col);
        area = vector<int>(row * col, 0);

        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                int idx = r * col + c;
                parent[idx] = idx;

                if (grid[r][c] == 1)
                {
                    area[idx] = 1;
                }
                else
                {
                    area[idx] = 0;
                }
            }
        }

        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if (grid[r][c] == 0)
                    continue;

                int idx = r * col + c;

                if (r - 1 >= 0 && grid[r - 1][c] == 1)
                {
                    unit(r, c, r - 1, c);
                }

                if (r + 1 < row && grid[r + 1][c] == 1)
                {
                    unit(r, c, r + 1, c);
                }

                if (c - 1 >= 0 && grid[r][c - 1] == 1)
                {
                    unit(r, c, r, c - 1);
                }

                if (c + 1 < col && grid[r][c + 1] == 1)
                {
                    unit(r, c, r, c + 1);
                }
            }
        }
    }

    int find(int idx)
    {
        if (parent[idx] != idx)
        {
            parent[idx] = find(parent[idx]);
        }
        return parent[idx];
    }

    void unit(int ar, int ac, int br, int bc)
    {
        int rootA = find(ar * col + ac);
        int rootB = find(br * col + bc);

        if (rootA == rootB)
            return;

        if (area[rootA] < area[rootB])
        {
            parent[rootA] = rootB;
            area[rootB] = area[rootA] + area[rootB];
        }
        else
        {
            parent[rootB] = rootA;
            area[rootA] = area[rootA] + area[rootB];
        }
    }

    int islandArea(int r, int c)
    {
        int root = find(r * col + c);
        return area[root];
    }

private:
    vector<int> parent;
    vector<int> area;
    int row;
    int col;
};

class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();

        UnoinFind uf(grid);

        int ans = 0;
        unordered_set<int> rootSet;

        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if (grid[r][c] == 1)
                {
                    ans = max(ans, uf.islandArea(r, c));
                }
                else
                {
                    int islandArea = 0;
                    int root;
                    rootSet.clear();

                    if (r - 1 >= 0 && grid[r - 1][c] == 1)
                    {
                        root = uf.find((r - 1) * col + c);
                        if (rootSet.count(root) == 0)
                        {
                            islandArea += uf.islandArea(r - 1, c);
                            rootSet.insert(root);
                        }
                    }

                    if (r + 1 < row && grid[r + 1][c] == 1)
                    {
                        root = uf.find((r + 1) * col + c);
                        if (rootSet.count(root) == 0)
                        {
                            islandArea += uf.islandArea(r + 1, c);
                            rootSet.insert(root);
                        }
                    }

                    if (c - 1 >= 0 && grid[r][c - 1] == 1)
                    {
                        root = uf.find(r * col + c - 1);
                        if (rootSet.count(root) == 0)
                        {
                            islandArea += uf.islandArea(r, c - 1);
                            rootSet.insert(root);
                        }
                    }

                    if (c + 1 < col && grid[r][c + 1] == 1)
                    {
                        root = uf.find(r * col + c + 1);
                        if (rootSet.count(root) == 0)
                        {
                            islandArea += uf.islandArea(r, c + 1);
                            rootSet.insert(root);
                        }
                    }

                    ans = max(ans, islandArea + 1);
                }
            }
        }

        return ans;
    }
};
// @lc code=end
