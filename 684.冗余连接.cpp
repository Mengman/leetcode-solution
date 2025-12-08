/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

// @lc code=start
class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        // 方法：通过并查集来做
        // 根据 edge 来 union 两个节点
        // 如果 两个节点已经连通，那么这就是一个冗余边
        vector<int> ans;
        int nodeNum = 0;

        for (auto edge : edges)
        {
            if (edge[0] > nodeNum)
                nodeNum = edge[0];

            if (edge[1] > nodeNum)
                nodeNum = edge[1];
        }

        parent = vector<int>(nodeNum);
        for (int i = 0; i < nodeNum; i++)
        {
            parent[i] = i;
        }

        for (auto edge : edges)
        {
            if (!Union(edge[0] - 1, edge[1] - 1))
            {
                ans = edge;
            }
        }

        return ans;
    }

private:
    vector<int> parent;

    bool Union(int x, int y)
    {
        int xr = Find(x);
        int yr = Find(y);

        if (xr == yr)
        {
            return false;
        }
        else
        {
            parent[yr] = xr;
        }

        return true;
    }

    int Find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = Find(parent[x]);
        }

        return parent[x];
    }
};
// @lc code=end
