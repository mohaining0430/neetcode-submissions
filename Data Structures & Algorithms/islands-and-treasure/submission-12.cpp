// Multi-source BFS
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int rowcnt = grid.size(), colcnt = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < rowcnt; ++i)
            for (int j = 0; j < colcnt; ++j)
                if (grid[i][j] == 0)
                    q.push({i, j});
        
        int level = 0;
        while (!q.empty()) {
            level++;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int curx = q.front().first, cury = q.front().second;
                q.pop();
                for (const auto dir : dirs) {
                    int nextx = curx + dir[0], nexty = cury + dir[1];
                    if (nextx < 0 || nextx >= rowcnt || nexty < 0 || nexty >= colcnt
                            || grid[nextx][nexty] != INT_MAX)
                        continue;
                    grid[nextx][nexty] = level;
                    q.push({nextx, nexty});
                }
            }
        }
    }
};