/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 */

// @lc code=start
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // return traversalSolution(grid);

        return dfsSolution(grid);
    }

    int traversalSolution(vector<vector<int>>& grid) {
        int length = 0;
        int nr = grid.size();
        int nc = grid[0].size();

        for(int r = 0; r < nr; ++r) {
            for(int c = 0; c < nc; ++c) {
                if (grid[r][c] == 1) {
                    if(r-1 < 0 || grid[r-1][c] == 0) length++;
                    if(r+1 >= nr || grid[r+1][c] == 0) length++;
                    if(c-1 < 0 || grid[r][c-1] == 0) length++;
                    if(c+1 >= nc || grid[r][c+1] == 0) length++;
                }
            }
        }
        return length;
    }

    int dfsSolution(vector<vector<int>>& grid) {
        int length = 0;
        int nr = grid.size();
        int nc = grid[0].size();
        vector<vector<bool>> visited(nr, vector<bool>(nc, false));

        for(int r = 0; r < nr; ++r) {
            for(int c = 0; c < nc; ++c) {
                if (grid[r][c] == 1 && !visited[r][c]) {
                    length += dfs(grid, visited, r, c);
                }
            }
        }

        return length;
    }

    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c) {
        visited[r][c] = true;
        if (grid[r][c] == 0) return 0;

        int nr = grid.size();
        int nc = grid[0].size();

        int length = 0;
        if(r-1 < 0 || grid[r-1][c] == 0) length++;
        if(r+1 >= nr || grid[r+1][c] == 0) length++;
        if(c-1 < 0 || grid[r][c-1] == 0) length++;
        if(c+1 >= nc || grid[r][c+1] == 0) length++;

        if ((r-1 >= 0 && grid[r-1][c] == 1) && !visited[r-1][c]) length += dfs(grid, visited, r-1, c);
        if ((r+1 < nr && grid[r+1][c] == 1) && !visited[r+1][c]) length += dfs(grid, visited, r+1, c);
        if ((c-1 >= 0 && grid[r][c-1] == 1) && !visited[r][c-1]) length += dfs(grid, visited, r, c-1);
        if ((c+1 < nc && grid[r][c+1] == 1) && !visited[r][c+1]) length += dfs(grid, visited, r, c+1);

        return length;
    }
};
// @lc code=end

