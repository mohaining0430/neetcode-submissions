class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int rowcnt = grid.size(), colcnt = grid[0].size();
        visited = vector<vector<bool>>(rowcnt, vector<bool>(colcnt, false));
        int res = 0;
        for (int i = 0; i < rowcnt; ++i) {
            for (int j = 0; j < colcnt; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int row, int col) {
        int rowcnt = grid.size(), colcnt = grid[0].size();
        if (row < 0 || col < 0 || row >= rowcnt || col >= colcnt
            || grid[row][col] == '0' || visited[row][col])
            return;
        visited[row][col] = true;
        for (int i = 0; i < 4; ++i) 
            dfs(grid, row + dirs[i][0], col + dirs[i][1]);
    }


private:
    vector<vector<bool>> visited;
    vector<vector<int>> dirs ={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};
