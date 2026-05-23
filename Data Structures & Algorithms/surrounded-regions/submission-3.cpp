class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rowcnt = board.size(), colcnt = board[0].size();
        vector<vector<bool>> visited(rowcnt, vector<bool>(colcnt, false));
        queue<std::pair<int, int>> q;
        for (int i = 0; i < rowcnt; ++i) {
            if (board[i][0] == 'O')
                q.push({i, 0});
            if (board[i][colcnt - 1] == 'O')
                q.push({i, colcnt - 1});            
        }
        for (int i = 1; i < colcnt - 1; ++i) {
            if (board[0][i] == 'O')
                q.push({0, i});
            if (board[rowcnt - 1][i] == 'O')
                q.push({rowcnt - 1, i});            
        }

        while (!q.empty()) {
            int curx = q.front().first, cury = q.front().second;
            q.pop();
            visited[curx][cury] = true;
            for (int i = 0; i < 4; ++i) {
                int nextx = curx + dirs[i][0], nexty = cury + dirs[i][1];
                if (nextx >=0 && nextx <= rowcnt - 1 && nexty >= 0 && nexty <= colcnt - 1
                        && !visited[nextx][nexty] && board[nextx][nexty] == 'O') {
                    q.push({nextx, nexty});
                }
            }
        }

        for (int i = 0; i < rowcnt; ++i) 
            for (int j = 0; j < colcnt; ++j)
                if (!visited[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
    }

private:
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};
