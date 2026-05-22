class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> output;
        dfs(nums, res, output, 0);
        return res;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& output, int index) {
        if (index == nums.size()) {
            res.push_back(output);
            return;
        }
        output.push_back(nums[index]);
        dfs(nums, res, output, index + 1);
        output.pop_back();
        dfs(nums, res, output, index + 1);
    }
};
