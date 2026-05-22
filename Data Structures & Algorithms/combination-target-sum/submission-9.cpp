class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> output;
        dfs(nums, 0, 0, target, output, res);
        return res;
    }

    void dfs(vector<int>& nums, int index, int cur_sum, int target, 
            vector<int>& output, vector<vector<int>>& res) {
        if (index == nums.size()) {
            if (cur_sum == target) {
                res.push_back(output);
            }
            return;
        }

        if (cur_sum > target)
            return;

        output.push_back(nums[index]);
        dfs(nums, index, cur_sum + nums[index], target, output, res);
        output.pop_back();
        dfs(nums, index + 1, cur_sum, target, output, res);
    }
};
