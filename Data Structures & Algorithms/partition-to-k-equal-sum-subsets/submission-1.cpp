class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        vector<bool> visited(nums.size(), false);
        int sum = 0;
        for (const auto num : nums)
            sum += num;
        if (sum % k != 0)
            return false;
        sum /= k;
        sort(nums.rbegin(), nums.rend());
        return dfs(nums, visited, k, 0, 0, sum);
    }

    bool dfs(vector<int>& nums, vector<bool>& visited, int k, int index, int cur_sum, int target) {
        if (k == 0)
            return true;
        if (cur_sum == target) 
            return dfs(nums, visited, k - 1, 0, 0, target);
        if (index == nums.size())
            return false;
        for (int i = index; i < nums.size(); ++i) {
            if (!visited[i] && cur_sum + nums[i] <= target) {
                visited[i] = true;
                if (dfs(nums, visited, k, i + 1, cur_sum + nums[i], target))
                    return true;
                visited[i] = false;
            }
        }
        return false;
    }
};