class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size();
        int res = 0;
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        for (int i = len - 1; i >= 0; --i) {
            for (int j = i; j < len; ++j) {
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    res++;
                }
            }
        }
        return res;
    }
};
