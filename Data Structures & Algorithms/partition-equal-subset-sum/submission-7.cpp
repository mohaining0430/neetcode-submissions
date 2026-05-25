class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (const auto num : nums)
            sum += num;
        if (sum % 2 != 0)
            return false;
        sum /= 2;

        return dfs(nums, 0, 0, sum);
    }

    bool dfs(vector<int>& nums, int index, int cur_sum, int target) {
        if (index == nums.size()) {
            if (cur_sum == target)
                return true;
            return false;
        }
        if (cur_sum > target)
            return false;
         // return early here
        if (cur_sum == target)
            return true;       
        if (dfs(nums, index + 1, cur_sum + nums[index], target) ||
            dfs(nums, index + 1, cur_sum, target))
            return true;
        return false;
    }
};
