class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rowcnt = board.size(), colcnt = board[0].size();
        visited = vector<vector<bool>>(rowcnt, vector<bool>(colcnt, false));
        for (int i = 0; i < rowcnt; ++i) 
            for (int j = 0; j < colcnt; ++j)
                if (dfs(board, word, i, j, 0))
                    return true;
        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int row, int col, int index) {
        if (index == word.size())
            return true;
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()
                || board[row][col] != word[index] || visited[row][col])
            return false;
        visited[row][col] = true;
        if (dfs(board, word, row - 1, col, index + 1) 
                || dfs(board, word, row + 1, col, index + 1)
                || dfs(board, word, row, col - 1, index + 1)
                || dfs(board, word, row, col + 1, index + 1))
            return true;
        visited[row][col] = false;
        return false;
    }

private:
    vector<vector<bool>> visited;
};
