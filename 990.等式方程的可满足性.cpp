/*
 * @lc app=leetcode.cn id=990 lang=cpp
 *
 * [990] 等式方程的可满足性
 */

// @lc code=start
class UnionFind {
private:
    vector<int> group;
public:
    UnionFind(int n) {
        group.resize(n);
        for (int i = 0; i < n; i++) {
            group[i] = i;
        }
    }

    int find(int x) {
        while (x != group[x]) {
            group[x] = group[group[x]];
            x = group[x];
        }
        return x;
    }

    void merge(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);

        if (root_x != root_y) {
            group[root_y] = root_x;
        }
    }

    bool isConnect(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf(26);
        for(auto eq : equations) {
            if (eq[1] == '=') {
                int lop = (int) eq[0] - 97;
                int rop = (int) eq[3] - 97;
                uf.merge(lop, rop);
            }
        }

        for(auto eq : equations) {
            if (eq[1] == '!') {
                int lop = (int) eq[0] - 97;
                int rop = (int) eq[3] - 97;
                if (uf.isConnect(lop, rop)) {
                    return false;
                }
            }
        }
        return true;
        
    }
};
// @lc code=end

