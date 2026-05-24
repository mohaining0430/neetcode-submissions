class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        int res = 0;
        for (int i = len - 1; i >= 0; --i) {
            for (int j = i; j <= len - 1; ++j) {
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    res++;
                }
            }
        }
        return res;
    }
};
