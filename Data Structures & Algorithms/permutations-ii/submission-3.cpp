class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> output;
        set<vector<int>> res;
        dfs(nums, output, res, 0);
        return vector<vector<int>>(res.begin(), res.end());
    }

    void dfs(vector<int>& nums, vector<int>& output, set<vector<int>>& res, 
            int index) {
        if (index == nums.size()) {
            res.insert(output);
            return;
        }
        for (int i = index; i < nums.size(); ++i) {
            swap(nums[index], nums[i]);
            output.push_back(nums[index]);
            dfs(nums, output, res, index + 1);
            output.pop_back();
            swap(nums[index], nums[i]);
        }
    }
};