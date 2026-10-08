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
        return dfs(matchsticks, visited, 0, sum, 0, 0);
    }

    bool dfs(vector<int>& sticks, vector<bool>& visited, int cur_sum, int target, int cnt, int index) {
        if (cnt == 4)
            return true;
        if (cur_sum > target)
            return false;
        if (index == sticks.size()) 
            return cur_sum == target ? dfs(sticks, visited, 0, target, cnt + 1, 0) : false;
        if (visited[index])
            return dfs(sticks, visited, cur_sum, target, cnt, index + 1);
        if (dfs(sticks, visited, cur_sum, target, cnt, index + 1))
            return true;        
        visited[index] = true;
        if (dfs(sticks, visited, cur_sum + sticks[index], target, cnt, index + 1))
            return true;
        visited[index] = false;
        return false;
    }
};