class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int rowcnt = grid.size(), colcnt = grid[0].size();
        vector<vector<bool>> visited(rowcnt, vector<bool>(colcnt, false));
        int res = 0;
        for (int i = 0; i < rowcnt; ++i) {
            for (int j = 0; j < colcnt; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int cur = dfs(grid, visited, i, j);
                    res = max(res, cur);
                }
            }
        }
        return res;
    }

    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()
                || visited[i][j] || grid[i][j] == 0)
            return 0;
        visited[i][j] = true;
        int res = 1;
        for (const auto dir : dirs) {
            res += dfs(grid, visited, i + dir[0], j + dir[1]);
        }
        return res;
    }

private:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};
