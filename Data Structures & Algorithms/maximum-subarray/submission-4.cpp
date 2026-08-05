class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (dp[i - 1] <= 0) 
                dp[i] = nums[i];
            else
                dp[i] = dp[i - 1] + nums[i];
            res = max(res, dp[i]);
        } 
        return res;
    }
};
