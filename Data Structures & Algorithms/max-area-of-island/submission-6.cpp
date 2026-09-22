class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int rowCnt = grid.size(), colCnt = grid[0].size();
        int res = 0;
        visited = vector<vector<bool>>(rowCnt, vector<bool>(colCnt, false));
        for (int i = 0; i < rowCnt; ++i) {
            for (int j = 0; j < colCnt; ++j) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    res = max(res, dfs(grid, i, j));
                }
            }
        }
        return res;
    }

    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
                visited[i][j] || grid[i][j] == 0)
            return 0;
        visited[i][j] = true;
        int res = 1;
        for (auto dir : dirs) {
            int curx = i + dir[0], cury = j + dir[1];
            res += dfs(grid, curx, cury);
        }
        return res;
    }


private:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<bool>> visited;
};
