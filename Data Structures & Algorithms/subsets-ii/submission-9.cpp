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

        // You have two options:
        // 1. adding nums[index], then next dfs starts with index + 1
        // 2. not adding nums[index], then you have to skip nums[index + 1], nums[index + 2] etc. until 
        //    to nums[i], which is different from nums[index]
        output.push_back(nums[index]);
        dfs(nums, index + 1, output, res);
        output.pop_back();
        int i = index + 1;
        while (i < nums.size() && nums[i] == nums[i - 1])
            i++;
        dfs(nums, i, output, res);
    }
};