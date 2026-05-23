// Can skip. Hard to get right due to corner cases.
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int rowcnt = grid.size(), colcnt = grid[0].size();  
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        queue<std::pair<int, int>> q;
        // Track number of fresh fruits left for easier handling of corner cases.
        int fresh = 0;
        for (int i = 0; i < rowcnt; ++i) {
            for (int j = 0; j < colcnt; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int level = 0;
        while (fresh > 0 && !q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int curx = q.front().first, cury = q.front().second;
                q.pop();
                for (int j = 0; j < 4; ++j) {
                    int nextx = curx + dirs[j][0];
                    int nexty = cury + dirs[j][1];
                    if (nextx >= 0 && nexty >= 0 && nextx < rowcnt 
                        && nexty < colcnt && grid[nextx][nexty] == 1) {
                        grid[nextx][nexty] = 2;
                        q.push({nextx, nexty});
                        fresh--;
                    }
                }
            }
            level++;
        }  

        return fresh == 0 ? level : -1;
    }
};