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
        int rowcnt = board.size(), colcnt = board[0].size();
        if (row < 0 || col < 0 || row >= rowcnt || col >= colcnt 
            || visited[row][col] || board[row][col] != word[index])
            return false;
        visited[row][col] = true;
        bool res = dfs(board, word, index + 1, row + 1, col) ||
                dfs(board, word, index + 1, row - 1, col) ||
                dfs(board, word, index + 1, row, col + 1) ||
                dfs(board, word, index + 1, row, col - 1);
        /* Don't forget setting visited[row][col] back to false. Example:
            ["C","A","A"],
            ["A","A","A"],
            ["B","C","D"]
        */
        visited[row][col] = false;
        return res;
    }

private:
    vector<vector<bool>> visited;
};
