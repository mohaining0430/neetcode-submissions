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
        return dfs(matchsticks, visited, 0, 0, sum, 4);
    }

    bool dfs(vector<int>& sticks, vector<bool>& visited, int index, int cur_sum, 
                int target, int sides) {
        if (sides == 0)
            return true;
        if (cur_sum == target)
            return dfs(sticks, visited, 0, 0, target, sides - 1);
        for (int i = index; i < sticks.size(); ++i) {
            if (!visited[i] && cur_sum + sticks[i] <= target) {
                visited[i] = true;
                if (dfs(sticks, visited, i + 1, cur_sum + sticks[i], target, sides))
                    return true;
                visited[i] = false;
            }
        }
        return false;
    }
};