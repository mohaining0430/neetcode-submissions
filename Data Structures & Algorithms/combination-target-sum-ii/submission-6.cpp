class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end()); 
        vector<int> output;
        vector<vector<int>> res;
        dfs(candidates, target, 0, 0, output, res);
        return res;
    }

    void dfs(vector<int>& candidates, int target, int cur_sum, int index, 
                vector<int>& output, vector<vector<int>>& res) {
        if (cur_sum > target)
            return;
        if (cur_sum == target) {
            res.push_back(output);
            return;
        }
        if (index == candidates.size()) 
            return;

        // You have two options:
        // 1. adding nums[index], then next dfs starts with index + 1
        // 2. not adding nums[index], then you have to skip nums[index + 1], nums[index + 2] etc. until 
        //    to nums[i], which is different from nums[index]
        output.push_back(candidates[index]);
        dfs(candidates, target, cur_sum + candidates[index], index + 1, output, res);
        output.pop_back();
        int i = index + 1;
        while (i < candidates.size() && candidates[i] == candidates[i - 1])
            i++;
        dfs(candidates, target, cur_sum, i, output, res);
    }
};
