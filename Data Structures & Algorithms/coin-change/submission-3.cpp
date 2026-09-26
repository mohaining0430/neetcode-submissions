class Solution {
public:
    // Can skip
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(1 + amount, amount + 1);
        dp[0] = 0;
        for (int cur = 1; cur <= amount; ++cur) {
            for (const auto coin : coins) {
                if (cur >= coin) {
                    dp[cur] = min(dp[cur], 1 + dp[cur - coin]);
                }
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
