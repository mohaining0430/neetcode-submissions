class Solution {
public:
    int res = 0;

    int totalNQueens(int n) {
        string rowStr(n, '.');
        vector<string> board(n, rowStr);   
        dfs(board, 0);
        return res;
    }

    void dfs(vector<string>& board, int row) {
        if (row == board.size()) {
            res++;
            return;
        }
        for (int i = 0; i < board.size(); ++i) {
            if (isSafe(board, row, i)) {
                board[row][i] = 'Q';
                dfs(board, row + 1);
                board[row][i] = '.';
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