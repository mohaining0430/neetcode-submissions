class Solution {
public:
    // Can skip.
    // Bottom up DP.
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& i1, 
                auto& i2) {
            return i1[1] < i2[1];
        });       

        // Max number of non-overlapping intervals that can be kept.
        vector<int> dp(intervals.size(), 0);
        int res = 0;
        for (int i = 0; i < intervals.size(); ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (intervals[j][1] <= intervals[i][0]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return intervals.size() - res;
    }
};
