/*
 * @lc app=leetcode.cn id=1376 lang=cpp
 *
 * [1376] 通知所有员工所需的时间
 */

// @lc code=start
struct QNode {
    int vno;     // 员工ID
    int length;  // 通知到达员工的时间
};

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                adj[manager[i]].push_back(i);
            }
        }
        QNode e, e1;
        e.vno = headID;
        e.length = informTime[headID];
        queue<QNode> qu;
        qu.push(e);
        int ans = 0;
        while (!qu.empty())
        {
            e = qu.front(); qu.pop();
            int u = e.vno, length = e.length;
            for(int v : adj[u]) {
                e1.vno = v;
                e1.length = length + informTime[v];
                if(adj[v].size() == 0) {
                    ans = max(ans, e1.length);
                } else {
                    qu.push(e1);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

