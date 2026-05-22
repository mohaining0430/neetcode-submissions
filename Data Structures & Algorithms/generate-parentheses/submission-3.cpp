class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string output;
        vector<string> res;
        dfs(n, 0, 0, output, res);
        return res;
    }

    void dfs(int n, int left, int right, string& output, vector<string>& res) {
        if (left == n && right == n) {
            res.push_back(output);
            return;
        }

        // You have two options: add a "(" or a ")".
        if (left < n) {
            output.push_back('(');
            dfs(n, left + 1, right, output, res);
            output.pop_back();
        }

        if (right < left) {
             output.push_back(')');
            dfs(n, left, right + 1, output, res);
            output.pop_back();           
        }
    }
};
