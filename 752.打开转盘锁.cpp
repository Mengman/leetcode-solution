/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

// @lc code=start
struct Node {
    string status;
    int g;
    int h;

    bool operator > (const Node& other) const {
        return (g + h) > (other.g + other.h);
    }
};

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        
        if (dead.count("0000")) return -1;
        if (target == "0000") return 0;

        priority_queue<Node, vector<Node>, greater<Node>> pq;
        unordered_map<string, int> visited;

        string start(target.size(), '0');
        pq.push({start, 0, getDistance(start, target)});
       
        visited[start] = 0;

        while (!pq.empty())
        {
            Node node  = pq.top();
            pq.pop();
            if (node.status == target) return node.g;

            // 做 BFS
            // 每个位置可以前后各滚动一次
            for(string& next_status : getNext(node.status)){
                // 死亡数字，跳过
                if(dead.count(next_status)) continue;

                // 如果步骤数量大于等于最小记录，跳过
                if(visited.count(next_status) && node.g + 1 >= visited[next_status]) {
                    continue;
                }
                
                visited[next_status] = node.g + 1;
                pq.push({next_status, node.g + 1, getDistance(next_status, target)});
            }
        }

        return -1;
    }

    // 获取当前状态旋转一位能达到的所有状态
    vector<string> getNext(string& s) {
        vector<string> res;
        for (int i = 0; i < 4; ++i) {
            char num = s[i];
            // 向上拨
            s[i] = (num == '9' ? '0' : num + 1);
            res.push_back(s);
            // 向下拨
            s[i] = (num == '0' ? '9' : num - 1);
            res.push_back(s);
            // 恢复现场
            s[i] = num;
        }
        return res;
    }

    int getDistance(const string& status, const string& target) {
        int dist = 0;

        for(int i = 0; i < target.size(); i++) {
            int d = abs(target[i] - status[i]);
            // 考虑 0-9 循环，取顺时针和逆时针的最小值
            dist += min(d, 10 - d);
        }
        return dist;
    }
};
// @lc code=end

