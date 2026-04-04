/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class UnionFind {
public:
    UnionFind(vector<vector<char>>& grid) {
        int heigh = grid.size();
        int width = grid[0].size();
        for(int y = 0; y < heigh; ++y) {
            for(int x = 0; x < width; ++x) {
                if(grid[y][x] == '1') {
                    parent.push_back(y * width + x);
                    ++count;
                } else {
                    parent.push_back(-1);
                }

                rank.push_back(0);
            }
        }
    }

    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }

        return parent[i];
    }

    void unite(int i, int j) {
        int root1 = find(i);
        int root2 = find(j);
        if (root1 != root2) {
            if (rank[root1] < rank[root2]) {
                swap(root1, root2);
            }
            parent[root2] = root1;
            if (rank[root1] == rank[root2]) rank[root1]++;
            --count;
        }
    }

    int getCount() const {
        return count;
    }
private:
    vector<int> parent;
    vector<int> rank;
    int count = 0;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int heigh = grid.size();
        if (!heigh) return 0;

        // return dfsSolution(grid);

        // return bfsSolution(grid);

        return unionfindSolution(grid);
    }

    int dfsSolution(vector<vector<char>>& grid) {
        int h = grid.size();
        int w = grid[0].size();

        int islandNums = 0;
        for(int y = 0; y < h; ++y) {
            for(int x = 0; x < w; ++x) {
                if (grid[y][x] == '1') {
                    islandNums++;
                    dfs(grid, x, y, h, w);
                }
            }
        }

        return islandNums;
    }

    void dfs(vector<vector<char>>& grid, int x, int y, int h, int w) {
        grid[y][x] = '0';
        
        // top
        if (y-1 >= 0 && grid[y-1][x] == '1') dfs(grid, x, y-1, h, w);
        // down
        if (y+1 < h && grid[y+1][x] == '1') dfs(grid, x, y+1, h, w);
        // left
        if (x-1 >= 0 && grid[y][x-1] == '1') dfs(grid, x-1, y, h, w);
        // right
        if (x+1 < w && grid[y][x+1] == '1') dfs(grid, x+1, y, h, w);
    }

    int bfsSolution(vector<vector<char>>& grid) {
        int h = grid.size();
        int w = grid[0].size();

        queue<pair<int, int>> qu;

        int islandNums = 0;
        for(int y = 0; y < h; ++y) {
            for(int x = 0; x < w; ++x) {
                if (grid[y][x] == '1') {
                    islandNums++;
                    grid[y][x] = '0';
                    qu.push({y, x});

                    while (!qu.empty())
                    {
                        auto [r, c] = qu.front();
                        qu.pop();
                        //top
                        if(r-1 >= 0 && grid[r-1][c] == '1') {
                            grid[r-1][c] = '0';
                            qu.push({r-1, c});
                        }

                        // down
                        if(r+1 < h && grid[r+1][c]=='1') {
                            grid[r+1][c] = '0';
                            qu.push({r+1, c});
                        }

                        // left
                        if(c-1 >= 0 && grid[r][c-1] == '1') {
                            grid[r][c-1] = '0';
                            qu.push({r, c-1});
                        }

                        // right
                        if(c+1 < w && grid[r][c+1] == '1') {
                            grid[r][c+1] = '0';
                            qu.push({r, c+1});
                        }
                    }
                    
                }
            }
        }
        return islandNums;
    }

    int unionfindSolution(vector<vector<char>>& grid) {
        UnionFind uf(grid);
        int heigh = grid.size();
        int width = grid[0].size();

        for(int y = 0; y < heigh; ++y) {
            for(int x = 0; x < width; ++x) {
                if (grid[y][x] == '1') {
                    grid[y][x] = '0';
                    int idx = y*width+x;

                    if(y-1 >= 0 && grid[y-1][x] == '1') uf.unite(idx, (y-1)*width+x);
                    if(y+1 < heigh && grid[y+1][x] == '1') uf.unite(idx, (y+1)*width+x);
                    if(x-1 >= 0 && grid[y][x-1] == '1') uf.unite(idx, y*width+x-1);
                    if(x+1 < width && grid[y][x+1] == '1') uf.unite(idx, y*width+x+1);
                }
            }
        }

        return uf.getCount();
    }
};
// @lc code=end

