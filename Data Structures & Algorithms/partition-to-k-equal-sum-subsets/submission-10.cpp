class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (const auto num : nums)
            sum += num;
        if (sum % k != 0)
            return false;
        int target = sum / k;
        vector<bool> visited(nums.size(), false);
        return dfs(nums, visited, k, 0, 0, target);
    }

    bool dfs(vector<int>& nums, vector<bool>& visited, int k, int index, int cur_sum, int target) {
        if (k == 0)
            return true;
        if (cur_sum == target) 
            return dfs(nums, visited, k - 1, 0, 0, target);
        if (cur_sum > target)
            return false;
        if (index == nums.size())
            return false;
        if (visited[index])
            return dfs(nums, visited, k, index + 1, cur_sum, target);
        visited[index] = true;
        if (dfs(nums, visited, k, index + 1, cur_sum + nums[index], target))
            return true;
        visited[index] = false;
        if (dfs(nums, visited, k, index + 1, cur_sum, target))
            return true;
        return false;
    }
};