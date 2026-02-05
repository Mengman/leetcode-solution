/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 */

// @lc code=start
struct Edge {
    int vno;        // 节点 ID
    int wt;  // 消息到达节点的用时

    Edge(int v, int w): vno(v), wt(w) {}
};


struct QNode {
    int vno;
    int length;

    bool operator < (const QNode& b) const {
        return length > b.length;
    }
};

class Solution {
    const int INF = 0x3f3f3f3f;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // 解法1： 分支界限法
        return branchAndBound(times, n , k);

        // 解法2： 优先队列分支界限发
        // return priorityBranchAndBound(times, n, k);
    }

    int branchAndBound(vector<vector<int>>& times, int n, int k) {
        vector<vector<Edge>> adj(n);
        for(vector<int>e : times) {
            adj[e[0] - 1].push_back(Edge(e[1] - 1, e[2]));
        }

        int s = k - 1;
        vector<int> dist(n, INF);
        dist[s] = 0;
        queue<int> qu;
        qu.push(s);

        while (!qu.empty())
        {
            int u = qu.front(); qu.pop();
            for(auto e : adj[u]) {
                if(dist[u] + e.wt < dist[e.vno]) {
                    dist[e.vno] = dist[u] + e.wt;
                    qu.push(e.vno);
                }
            }
        }

        int ans = dist[0];
        for(int d : dist) {
            if (d > ans) ans = d;
        }

        if (ans == INF) return -1;
        else return ans;
    }


    int priorityBranchAndBound(vector<vector<int>>& times, int n, int k) {
        vector<vector<Edge>> adj(n);
        for(vector<int> t : times) {
            adj[t[0]-1].push_back(Edge(t[1]-1, t[2]));
        }

        int s = k - 1;
        vector<int> dist(n, INF);
        dist[s] = 0;
        QNode e, e1;
        priority_queue<QNode> pqu;
        e.vno = s;
        e.length = 0;
        pqu.push(e);

        while (!pqu.empty())
        {
            e = pqu.top(); pqu.pop();
            for(auto a : adj[e.vno]) {
                if(dist[e.vno] + a.wt < dist[a.vno]) {
                    dist[a.vno] = dist[e.vno] + a.wt;
                    e1.vno = a.vno;
                    e1.length = dist[a.vno];
                    pqu.push(e1);
                }
            }
        }

        int ans = dist[0];
        for(int d : dist) {
            if (d > ans) ans = d;
        }

        if (ans == INF) return -1;
        else return ans;
    }
};
// @lc code=end

