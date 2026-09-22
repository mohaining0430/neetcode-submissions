class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for (const auto stick : matchsticks) 
            sum += stick;
        if (sum % 4 != 0)
            return false;
        sum /= 4;
        vector<bool> visited(matchsticks.size(), false);
        return dfs(matchsticks, visited, 0, 0, sum, 0);
    }

    bool dfs(vector<int>& matchsticks, vector<bool>& visited, int index, int cur_sum, int target, int parts) {
        if (parts == 4) 
            return true;
        if (index == matchsticks.size())
            return cur_sum == target ? dfs(matchsticks, visited, 0, 0, target, parts + 1): false;
        if (cur_sum > target)
            return false;
        if (visited[index])
            return dfs(matchsticks, visited, index + 1, cur_sum, target, parts);
        if (dfs(matchsticks, visited, index + 1, cur_sum, target, parts))
            return true;
        visited[index] = true;
        if (dfs(matchsticks, visited, index + 1, cur_sum + matchsticks[index], target, parts))
            return true;
        visited[index] = false;
        return false;
    }
};