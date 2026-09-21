class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> output;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, 0, target, output, res);
        return res;
    }

    void dfs(vector<int>& nums, int index, int cur_sum, int target, vector<int>& output, vector<vector<int>>& res) {
        if (cur_sum == target) {
            res.push_back(output);
            return;
        }
        if (cur_sum > target)
            return;
        if (index == nums.size())
            return;
        dfs(nums, index + 1, cur_sum, target, output, res);
        output.push_back(nums[index]);
        dfs(nums, index, cur_sum + nums[index], target, output, res);
        output.pop_back();
    }
};