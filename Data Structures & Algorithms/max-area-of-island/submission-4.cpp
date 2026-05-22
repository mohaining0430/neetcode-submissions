class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int rowcnt = grid.size(), colcnt = grid[0].size();
        visited = vector<vector<bool>>(rowcnt, vector<bool>(colcnt, false));
        int res = 0;

        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == 1 && !visited[row][col]) {
                    int cur = dfs(grid, row, col);
                    res = std::max(res, cur);
                }
            }
        }
        return res;        
    }

    int dfs(vector<vector<int>>& grid, int row, int col) {
        int rowcnt = grid.size(), colcnt = grid[0].size();
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        if (row < 0 || col < 0 || row >= rowcnt || col >= colcnt ||
            visited[row][col] || grid[row][col] != 1)
            return 0;

        visited[row][col] = true;
        int res = 1;
        for (int i = 0; i < 4; ++i)
            res += dfs(grid, row + dirs[i][0], col + dirs[i][1]);
        return res;
    }   

private:
    vector<vector<bool>> visited;
    vector<vector<int>> dirs ={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};
