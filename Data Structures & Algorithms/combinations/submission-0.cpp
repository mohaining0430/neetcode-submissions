class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> output;
        vector<vector<int>> res;
        dfs(n, k, output, res, 1);
        return res;
    }

    void dfs(int n, int k, vector<int>& output, vector<vector<int>>& res, int index) {
        if (k == 0) {
            res.push_back(output);
            return;
        }
        if (index == n + 1)
            return;
        output.push_back(index);
        dfs(n, k - 1, output, res, index + 1);
        output.pop_back();
        dfs(n, k, output, res, index + 1);
    }
};