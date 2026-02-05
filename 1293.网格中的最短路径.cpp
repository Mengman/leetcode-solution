/*
 * @lc app=leetcode.cn id=1293 lang=cpp
 *
 * [1293] 网格中的最短路径
 */

// @lc code=start

struct QNode {
    int x;          // x 坐标
    int y;          // y 坐标
    int length;     // (0,0) 到 (x,y) 的路径长度
    int obstacles;  // (0,0) 到 (x,y) 的障碍数量

    bool operator < (const QNode& other) const {
        return length > other.length;
    }
};

class Solution {
    const int INF = 0x3f3f3f3f;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0}; // 上、下、右、左
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        // 解法1：优先队列分支界限法 (超时)
        // return priorityBranchAndBound(grid, k);
        // 解法2：广度优先遍历
        return bfs(grid, k);
    }

    int priorityBranchAndBound(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        if(k > m+n-2) return m+n-2;
        vector<vector<int>> cnt(m, vector<int>(n, INF));
        QNode e, e1;
        priority_queue<QNode> pqu;
        e.x=0; e.y=0; e.length=0; e.obstacles=0;
        pqu.push(e);
        cnt[0][0] = 0;
        int ans = INF;

        while (!pqu.empty())
        {
            e = pqu.top(); pqu.pop();
            int x = e.x, y = e.y, length = e.length, nums = e.obstacles;
            if(x == m - 1 && y == n - 1) ans = min(ans, length);

            // 在四周搜索
            for(int di = 0; di < 4; di++) {
                int nx = x + dx[di], ny = y + dy[di];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

                int nnums = nums + grid[nx][ny];
                if (nnums > k) continue;
                if (nnums > cnt[nx][ny]) continue;
                if (length + 1 < ans) {
                    cnt[nx][ny] = nnums;
                    e1.x = nx; 
                    e1.y = ny;
                    e1.length = length + 1;
                    e1.obstacles = cnt[nx][ny];
                    pqu.push(e1);
                }
            }
        }
        
        if(ans == INF) return -1;
        else return ans;
    }

    int bfs(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        if (k > m + n -2) return m + n - 2;

        vector<vector<vector<bool>>> visited(
            m, 
            vector<vector<bool>>(
                n, 
                vector<bool>(k+1, false)
            )
        );

        // 队列存储状态: {x, y, rest_k} 
        // rest_k 代表还能消除障碍物的个数
        queue<vector<int>> q;
        q.push({0, 0, k});
        visited[0][0][k] = true;
        
        int steps = 0;
        while (!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; ++i) {
                vector<int> curr = q.front();
                q.pop();

                int r = curr[0], c = curr[1], cur_k = curr[2];
                if (r == m - 1 && c == n - 1) return steps;

                for(int di = 0; di < 4; ++di) {
                    int nr = r + dy[di], nc = c + dx[di];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                    int next_k = cur_k - grid[nr][nc];

                    if (next_k >= 0 && !visited[nr][nc][next_k]) {
                        visited[nr][nc][next_k] = true;
                        q.push({nr, nc, next_k});
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};
// @lc code=end

