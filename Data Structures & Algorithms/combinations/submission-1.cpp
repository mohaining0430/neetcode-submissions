class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> output;
        vector<vector<int>> res;
        dfs(n, k, output, res, 1);
        return res;
    }

    void dfs(int n, int k, vector<int>& output, vector<vector<int>>& res, int cur) {
        if (k == 0) {
            res.push_back(output);
            return;
        }
        if (cur > n)
            return;
        output.push_back(cur);
        dfs(n, k - 1, output, res, cur + 1);
        output.pop_back();
        dfs(n, k, output, res, cur + 1);
    }
};