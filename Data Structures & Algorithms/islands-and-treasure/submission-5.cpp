class Solution {
public:
    // Multi-source BFS
    void islandsAndTreasure(vector<vector<int>>& grid) {
         if (grid.size() == 0 || grid[0].size() == 0)
            return;
        int rowcnt = grid.size(), colcnt = grid[0].size();  
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};   

        queue<std::pair<int, int>> q;
        for (int i = 0; i < rowcnt; ++i)
            for (int j = 0; j < colcnt; ++j)
                if (grid[i][j] == 0)
                    q.push({i, j});

        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int curx = q.front().first, cury = q.front().second;
                q.pop();
                for (int j = 0; j < 4; ++j) {
                    int nextx = curx + dirs[j][0];
                    int nexty = cury + dirs[j][1];
                    // If a node was previoulsy INT_MAX and no longer is now, it means that a 
                    // previous chest set that node already and the path from that node to the 
                    // previous chest is shorter than or equal to that to the current chest.
                    if (nextx < 0 || nexty < 0 || nextx >= rowcnt 
                        || nexty >= colcnt || grid[nextx][nexty] != INT_MAX) {
                        continue;
                    }
                    grid[nextx][nexty] = level + 1;
                    q.push({nextx, nexty});
                }
            }
            level++;
        }    
    }
};
