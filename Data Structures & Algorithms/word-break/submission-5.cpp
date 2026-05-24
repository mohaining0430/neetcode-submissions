class Solution {
public:
    // Use bottom-up DP to avoid timeout.
    // Can skip.
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        vector<bool> dp(len + 1, false);
        dp[len] = true;
    
        for (int i = len - 1; i >= 0; --i) {
            for (const auto word : wordDict) {
                if (s.substr(i, word.size()) == word) 
                    dp[i] = dp[i + word.size()];
                if (dp[i])
                    break;
            }
        }
        return dp[0];
    }
};

/*
// Recursion times out for larger test cases.
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return dfs(s, wordSet, 0);
    }

    bool dfs(string& s, unordered_set<string>& wordSet, int index) {
        if (index == s.size()) {
            return true;
        }

        for (int i = index; i < s.size(); ++i) {
            auto word = s.substr(index, i - index + 1);
            if (wordSet.contains(word)) {
                if (dfs(s, wordSet, i + 1)) {
                    return true;
                }
            }
        }
        return false;
    }
};
*/