class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> output;
        vector<vector<string>> res;
        dfs(s, 0, output, res);
        return res;
    }

    void dfs(string s, int index, vector<string>& output, vector<vector<string>>& res) {
        if (index == s.size()) {
            res.push_back(output);
            return;
        }
        for (int i = index; i < s.size(); ++i) {
            if (isPalin(s, index, i)) {
                output.push_back(s.substr(index, i - index + 1));
                dfs(s, i + 1, output, res);
                output.pop_back();
            }
        }
    }

    bool isPalin(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};