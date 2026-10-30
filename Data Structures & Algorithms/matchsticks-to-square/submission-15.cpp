class Solution {
public:
    bool makesquare(vector<int>& sticks) {
        int sum = 0;
        for (const auto stick : sticks)
            sum += stick;
        if (sum % 4 != 0)
            return false;
        int target = sum / 4;
        vector<bool> visited(sticks.size(), false);
        return dfs(sticks, visited, 0, 0, 0, target);
    }

    bool dfs(vector<int>& sticks, vector<bool>& visited, int cnt, int index, int cur_sum, int target) {
        if (cnt == 4)
            return true;
        if (cur_sum == target)
            return (dfs(sticks, visited, cnt + 1, 0, 0, target));
        if (cur_sum > target)
            return false;
        if (index == sticks.size())
            return false;
        if (visited[index])
            return dfs(sticks, visited, cnt, index + 1, cur_sum, target);
        visited[index] = true;
        if (dfs(sticks, visited, cnt, index + 1, cur_sum + sticks[index], target))
            return true;
        visited[index] = false;
        if (dfs(sticks, visited, cnt, index + 1, cur_sum, target))
            return true;
        return false;
    }
};