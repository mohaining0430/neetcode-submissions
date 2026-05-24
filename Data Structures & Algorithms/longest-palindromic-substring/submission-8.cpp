class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        vector<vector<bool>> dp(len, vector<bool>(len, false));

        int resLen = 0;
        string res;        
        for (int i = 0; i < len; ++i) {
            for (int j = i; j >= 0; --j) {
                if (s[i] == s[j] && (i - j <= 2 || dp[i - 1][j + 1])) {
                    dp[i][j] = true;
                    if (i - j + 1 > resLen) {
                        resLen = i - j + 1;
                        res= s.substr(j, i - j + 1);
                    }
                }
            }
        }
        return res;
    }
};
