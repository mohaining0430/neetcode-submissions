class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int rowcnt = grid.size(), colcnt = grid[0].size();
        visited = vector<vector<bool>>(rowcnt, vector<bool>(colcnt, false));
        int res = 0;
        for (int i = 0; i < rowcnt; ++i)
            for (int j = 0; j < colcnt; ++j)
                res = max(res, dfs(grid, i, j));
        return res;
    }

    int dfs(vector<vector<int>>& grid, int row, int col) {
        int rowcnt = grid.size(), colcnt = grid[0].size();
        if (row < 0 || row >= rowcnt || col < 0 || col >= colcnt
                || visited[row][col] || grid[row][col] == 0)
            return 0;
        visited[row][col] = true;
        int res = 1;
        for (const auto dir : dirs) {
            res += dfs(grid, row + dir[0], col + dir[1]);
        }
        return res;
    }


private:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<bool>> visited;
};
