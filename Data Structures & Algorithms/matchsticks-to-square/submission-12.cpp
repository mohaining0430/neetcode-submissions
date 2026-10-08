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
        return dfs(matchsticks, visited, 0, 0, 0, sum);
    }

    bool dfs(vector<int>& sticks, vector<bool>& visited, int index, int cnt, 
                        int cur_sum, int target) {
        if (cnt == 4)
            return true;
        if (cur_sum == target)
            return dfs(sticks, visited, 0, cnt + 1, 0, target);
        if (cur_sum > target)
            return false;
        if (index == sticks.size())
            return false;
        if (visited[index]) {
            return dfs(sticks, visited, index + 1, cnt, cur_sum, target);
        }
        visited[index] = true;
        if (dfs(sticks, visited, index + 1, cnt, cur_sum + sticks[index], target))
            return true;
        visited[index] = false;
        if (dfs(sticks, visited, index + 1, cnt, cur_sum, target))
            return true;       
        return false;
    }

};