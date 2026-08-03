class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
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

        output.push_back(nums[index]);
        dfs(nums, index + 1, output, res);
        output.pop_back();

        int i = index + 1;
        while (i < nums.size() && nums[i] == nums[index])
            i++;
        dfs(nums, i, output, res);
    }
};
