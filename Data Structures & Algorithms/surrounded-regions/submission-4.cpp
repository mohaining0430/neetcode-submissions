class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rowcnt = board.size(), colcnt = board[0].size();
        vector<vector<bool>> visited(rowcnt, vector<bool>(colcnt, false));
        queue<pair<int, int>> q;

        // Let the 'O's on the boarder of the board expand. The remaining 'O's
        // that have not been marked during the expansion are the surrounded 'O's.
        for (int c = 0; c < colcnt; ++c) {
            if (board[0][c] == 'O') {
                visited[0][c] = true;
                q.push({0, c});
            }
             if (board[rowcnt - 1][c] == 'O') {
                visited[rowcnt - 1][c] = true;
                q.push({rowcnt - 1, c});
            }           
        }
        for (int r = 1; r < rowcnt - 1; ++r) {
            if (board[r][0] == 'O') {
                visited[r][0] = true;
                q.push({r, 0});
            }
             if (board[r][colcnt - 1] == 'O') {
                visited[r][colcnt - 1] = true;
                q.push({r, colcnt - 1});
            }    
        }

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int curx = q.front().first, cury = q.front().second;
                q.pop();
                for (int j = 0; j < 4; ++j) {
                    int nextx = curx + dirs[j][0];
                    int nexty = cury + dirs[j][1];
                    if (nextx >= 0 && nextx < rowcnt && nexty >= 0 && nexty < colcnt 
                        && !visited[nextx][nexty] && board[nextx][nexty] == 'O') {
                        visited[nextx][nexty] = true;
                        q.push({nextx, nexty});
                    }
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
