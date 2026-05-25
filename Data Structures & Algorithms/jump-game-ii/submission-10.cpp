class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp (nums.size(), INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j <= min(i + nums[i], (int)nums.size() - 1); ++j) {
                dp[j] = min(dp[i] + 1, dp[j]);
                // Optimization: return as soon as you can reach the last level.
                // There won't be a shorter path from a higher level than level i to  
                // reach the last level, because it takes longer to reach that level
                // than to reach level i.                
                if (j == nums.size() - 1) {
                    return dp[nums.size() - 1];
                }
            }
        }
        return dp[nums.size() - 1];
    }
};

/*
// DFS -- timed out
class Solution {
public:
    int jump(vector<int>& nums) {
        int steps = 0;
        dfs(nums, 0, steps);
        return res == INT_MAX ? -1 : res;
    }

    void dfs(vector<int>& nums, int index, int& steps) {
        if (index >= nums.size() - 1) {
            res = min(res, steps);
            return;
        }

        for (int i = 1; i <= nums[index]; ++i) {
            steps++;
            dfs(nums, index + i, steps);
            steps--;
        }
    }

private:
    int res = INT_MAX;
};
*/
