class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rowcnt = board.size(), colcnt = board[0].size();
        vector<vector<bool>> visited(rowcnt, vector<bool>(colcnt, false));
        queue<pair<int, int>> q;

        // Let the 'O's on the boarder of the board expand. The remaining 'O's
        // that have not been marked during the expansion are the surrounded 'O's.
        for (int c = 0; c < colcnt; ++c) {
            if (board[0][c] == 'O') 
                q.push({0, c});
        
             if (board[rowcnt - 1][c] == 'O') 
                q.push({rowcnt - 1, c});          
        }
        for (int r = 1; r < rowcnt - 1; ++r) {
            if (board[r][0] == 'O')
                q.push({r, 0});
        
             if (board[r][colcnt - 1] == 'O') 
                q.push({r, colcnt - 1}); 
        }     

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int curx = q.front().first, cury = q.front().second;
                q.pop();
                visited[curx][cury] = true;
                for (const auto dir : dirs) {
                    int nextx = curx + dir[0], nexty = cury + dir[1];
                    if (nextx < 0 || nextx >= rowcnt || nexty < 0 || nexty >= colcnt
                            || visited[nextx][nexty] || board[nextx][nexty] != 'O')
                        continue;
                    q.push({nextx, nexty});
                }
            }
        }  

        for (int i = 0; i < rowcnt; ++i) 
            for (int j = 0; j < colcnt; ++j)
                if (board[i][j] == 'O' && !visited[i][j])
                    board[i][j] = 'X';
    }

private:
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};
