/*
 * @lc app=leetcode.cn id=787 lang=cpp
 *
 * [787] K 站中转内最便宜的航班
 */

// @lc code=start
struct QNode {
    int vno;     // 节点 ID
    int cost;    // 当前花费
    int stops;   // 中转次数

    bool operator < (const QNode& other) const {
        return cost > other.cost; // 小根堆
    }

    QNode(int v, int c, int s): vno(v), cost(c), stops(s) {}
};

class Solution {
    const int INF = 0x3f3f3f3f;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // 使用分支界限法
        vector<vector<pair<int, int>>> adj(n);
        for(auto e : flights) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        
        // 2. 分支限界的核心：优先级队列
        priority_queue<QNode> pq;
        
        // 3. 剪枝备忘录：minCost[node][stops] 表示到达 node 时经过 stops 站的最小开销
        // 这里的 stops 指的是从 src 出发经过的边数 (最多 k+1 条边)
        vector<vector<int>> minCost(n, vector<int>(k + 2, INF));

        pq.push(QNode(src, 0, 0));
        minCost[src][0] = 0;

        while (!pq.empty()) {
            QNode q = pq.top();
            pq.pop();

            // 如果到达目的地，因为是优先队列，第一次到达的就是当前步数限制下的最小开销
            if (q.vno == dst) return q.cost;
            // 如果已经达到步数上限，不能再跳了
            if (q.stops > k) continue;

            // 遍历邻居
            for (auto& edge : adj[q.vno]) {
                int v = edge.first;
                int weight = edge.second;

                // 分支限界剪枝：只有当新路径成本更低时才进入分支
                if (q.cost + weight < minCost[v][q.stops + 1]) {
                    minCost[v][q.stops + 1] = q.cost + weight;
                    pq.push(QNode(v, minCost[v][q.stops + 1], q.stops + 1));
                }
            }
        }

        return -1;
    }
};
// @lc code=end

