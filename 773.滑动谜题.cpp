/*
 * @lc app=leetcode.cn id=773 lang=cpp
 *
 * [773] 滑动谜题
 */

// @lc code=start
struct Node {
    string status;
    int g;
    int h;

    bool operator > (const Node& other) const {
        return (g+h) > (other.g + other.h);
    }
};

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";
        string target = "123450";
        for(auto& row : board) for(int x : row) start += to_string(x);

        // 当0处在每个坐标可以交换的位置
        vector<vector<int>> neighbors = {
            {1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}
        };

        priority_queue<Node, vector<Node>, greater<Node>> pq;
        unordered_map<string, int> dist; // 记录到达该状态的最短步数 g

        pq.push({start, 0, getManhattan(start)});
        dist[start] = 0;

        while (!pq.empty())
        {
            Node curr = pq.top();
            pq.pop();

            if (curr.status == target) return curr.g;

            if (curr.g > dist[curr.status]) continue;

            int zeroPos = curr.status.find('0');
            for(int nextPos : neighbors[zeroPos]) {
                string nextStr = curr.status;
                swap(nextStr[zeroPos], nextStr[nextPos]);

                if(dist.find(nextStr) == dist.end() || curr.g + 1 < dist[nextStr]) {
                    dist[nextStr] = curr.g + 1;
                    pq.push({nextStr, curr.g + 1, getManhattan(nextStr)});
                }
            }
        }
        return -1;
    }

    int getManhattan(string status) {
        int dist = 0;
        // 目标状态中各数字对应的正确坐标 (r, c)
        // 1: (0,0), 2: (0,1), 3: (0,2), 4: (1,0), 5: (1,1), 0: 忽略
        static int targetPos[6][2] = {
            {1, 2}, {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}
        };

        for(int i = 0; i < 6; ++i) {
            int val = status[i] - '0';
            if (val == 0) continue;

            int currR = i / 3, currC = i % 3;
            int targetR = targetPos[val][0], targetC = targetPos[val][1];
            dist += abs(currR - targetR) + abs(currC - targetC);
        }
        return dist;
    }
};
// @lc code=end

