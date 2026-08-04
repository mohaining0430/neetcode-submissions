class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int rowCnt = grid.size(), colCnt = grid[0].size();
        visited = vector<vector<bool>>(rowCnt, vector<bool>(colCnt, false));
        int res = 0;
        for (int i = 0; i < rowCnt; ++i) {
            for (int j = 0; j < colCnt; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int area = dfs(grid, i, j);
                    res = max(res, area);
                }
            }
        }
        return res;
    }

    int dfs(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()
                || visited[row][col] || grid[row][col] == 0)
            return 0;
        visited[row][col] = true;
        int area = 1;
        for (auto dir : dirs) {
            area += dfs(grid, row + dir[0], col + dir[1]);
        }
        return area;
    }

private:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<bool>> visited;
};
