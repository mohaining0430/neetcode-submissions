class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        string rowStr(n, '.');
        vector<string> board(n, rowStr);
        vector<vector<string>> res;
        dfs(board, res, 0);
        return res;
    }

    void dfs(vector<string>& board, vector<vector<string>>& res, int row) {
        if (row == board.size()) {
            res.push_back(board);
            return;
        }
        for (int col = 0; col < board.size(); ++col) {
            if (isSafe(board, row, col)) {
                board[row][col] = 'Q';
                dfs(board, res, row + 1);
                board[row][col] = '.';
            }
        }
    }

    bool isSafe(vector<string>& board, int r, int c) {
        for (int i = r - 1; i >= 0; i--) {
            if (board[i][c] == 'Q') return false;
        }
        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        for (int i = r - 1, j = c + 1; i >= 0 && j < board.size(); i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        return true;       
    }
};
