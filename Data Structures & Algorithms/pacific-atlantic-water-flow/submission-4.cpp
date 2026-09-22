class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rowcnt = heights.size(), colcnt = heights[0].size();
        vector<vector<bool>> pac(rowcnt, vector<bool>(colcnt, false));
        vector<vector<bool>> atl(rowcnt, vector<bool>(colcnt, false));

        queue<pair<int, int>> pacQueue, atlQueue;

        for (int c = 0; c < colcnt; ++c) {
            pacQueue.push({0, c});
            atlQueue.push({rowcnt - 1, c});
        }
        for (int r = 0; r < rowcnt; ++r) {
            pacQueue.push({r, 0});
            atlQueue.push({r, colcnt - 1});
        }

        bfs(pacQueue, pac, heights);
        bfs(atlQueue, atl, heights);

        vector<vector<int>> res;
        for (int r = 0; r < rowcnt; ++r) {
            for (int c = 0; c < colcnt; ++c) {
                if (pac[r][c] && atl[r][c]) {
                    res.push_back({r, c});
                }
            }
        }
        return res;        
    }

private:
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void bfs(queue<std::pair<int, int>> &q, vector<vector<bool>> &ocean, 
                vector<vector<int>>& heights) {
        int rowcnt = heights.size(), colcnt = heights[0].size();
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int curx = q.front().first, cury = q.front().second;
                ocean[curx][cury] = true;
                q.pop();
                for (int j = 0; j < 4; ++j) {
                    int nextx = curx + dirs[j][0];
                    int nexty = cury + dirs[j][1];
                    if (nextx >= 0 && nextx < rowcnt && nexty >= 0 && nexty < colcnt 
                       && !ocean[nextx][nexty] // Don't enqueue an already visited point
                       && heights[nextx][nexty] >= heights[curx][cury]) {
                        q.push({nextx, nexty});
                    }
                }
            }
        }
    }
};
