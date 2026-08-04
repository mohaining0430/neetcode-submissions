class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rowcnt = board.size(), colcnt = board[0].size();
        visited = vector<vector<bool>>(rowcnt, vector<bool>(colcnt, false));
        for (int i = 0; i < rowcnt; ++i)
            for (int j = 0; j < colcnt; ++j)
                if (dfs(board, word, 0, i, j))
                    return true;
        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int index, int row, int col) {
        if (index == word.size())
            return true;
        if (row >= board.size() || col >= board[0].size() || board[row][col] != word[index]
                || visited[row][col])
            return false;
        visited[row][col] = true;
        if (dfs(board, word, index + 1, row - 1, col)
            || dfs(board, word, index + 1, row + 1, col)
            || dfs(board, word, index + 1, row, col - 1)
            || dfs(board, word, index + 1, row, col + 1))
            return true;
        visited[row][col] = false;
        return false;
    }

private:
    vector<vector<bool>> visited;
};
