class Solution {
public:
    // Multi-source BFS
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return;
        int rowcnt = grid.size(), colcnt = grid[0].size();  
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};   
        int level = 0;

        queue<pair<int, int>> q;
        for (int i = 0; i < rowcnt; ++i)
            for (int j = 0; j < colcnt; ++j)
                if (grid[i][j] == 0)
                    q.push({i, j});

        while (!q.empty()) {
            level++;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int curx = q.front().first, cury = q.front().second;
                q.pop();
                for (auto dir : dirs) {
                    int newx = curx + dir[0], newy = cury + dir[1];
                    if (newx < 0 || newy < 0 || newx >= rowcnt || newy >= colcnt ||
                            grid[newx][newy] != 2147483647)
                        continue;
                    grid[newx][newy] = level;
                    q.push({newx, newy});
                }
            }
        }
    }
};
