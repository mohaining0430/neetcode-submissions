class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), col = board[0].size();
        visited = vector<vector<bool>>(row, vector<bool>(col, false));
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (dfs(board, i, j, word, 0))
                    return true;
        return false;
    }

    bool dfs(vector<vector<char>>& board, int row, int col, string word, int index) {
        if (index == word.size())
            return true;
        if (row < 0 || col < 0 || row >= board.size() | col >= board[0].size()
                || visited[row][col] || board[row][col] != word[index])
            return false;
        visited[row][col] = true;
        if (dfs(board, row - 1, col, word, index + 1)|| 
                dfs(board, row + 1, col, word, index + 1)||
                dfs(board, row, col - 1, word, index + 1)||
                dfs(board, row, col + 1, word, index + 1))
            return true;
        visited[row][col] = false;
        return false;
    }

private:
    vector<vector<bool>> visited;

};