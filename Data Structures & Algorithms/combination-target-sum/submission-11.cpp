class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> output;
        vector<vector<int>> res;
        dfs(nums, output, res, 0, 0, target);
        return res;
    }

    void dfs(vector<int>& nums, vector<int>& output, vector<vector<int>>& res, int index, int cur_sum, int target) {
        if (cur_sum > target)
            return;
        if (cur_sum == target) {
            res.push_back(output);
            return;
        }
        if (index == nums.size())
            return;
        dfs(nums, output, res, index + 1, cur_sum, target);
        output.push_back(nums[index]);
        dfs(nums, output, res, index, cur_sum + nums[index], target);
        output.pop_back();
    }
};