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
        if (index == sticks.size())
            return false;

        if (visited[index] || cur_sum + sticks[index] > target)
            return dfs(sticks, visited, index + 1, cur_sum, target, sides);
        
        visited[index] = true;
        if (dfs(sticks, visited, index + 1, cur_sum + sticks[index], target, sides))
            return true;
        visited[index] = false;
        if (dfs(sticks, visited, index + 1, cur_sum, target, sides))
            return true;
        return false;
    }
};