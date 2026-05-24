class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        vector<vector<bool>> dp(len, vector<bool>(len, false));

        // Fill the right half triangle of the square - from bottom row to top row.
        int resLen = 0;
        string res;        
        for (int i = len - 1; i >= 0; --i) {
            for (int j = i; j < len; ++j) {
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    if (j - i + 1 > resLen) {
                        resLen = j - i + 1;
                        res = s.substr(i, j - i + 1);
                    }
                }
            }
        }

        return res;
    }
};
