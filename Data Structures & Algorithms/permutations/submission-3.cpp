class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> output;
        vector<vector<int>> res;
        dfs(nums, 0, output, res);
        return res;
    }

    void dfs(vector<int>& nums, int index, vector<int>& output, vector<vector<int>>& res) {
        if (index == nums.size()) {
            res.push_back(output);
            return;
        }

        for (int i = index; i < nums.size(); ++i) {
            swap(nums[index], nums[i]);
            output.push_back(nums[index]);
            dfs(nums, index + 1, output, res);
            output.pop_back();
            swap(nums[index], nums[i]);
        }
    }
};
