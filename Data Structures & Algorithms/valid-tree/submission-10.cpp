class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<vector<int>> neighbors(n, vector<int>());
        for (auto edge : edges) {
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);
        }
        queue<pair<int, int>> q;
        q.push({0, -1});
        while (!q.empty()) {
            int cur = q.front().first, parent = q.front().second;
            q.pop();
            visited[cur] = true;
            for (auto neighbor : neighbors[cur]) {
                if (neighbor == parent)
                    continue;
                if (visited[neighbor])
                    return false;
                q.push({neighbor, cur});
            }
        }

        for (int i = 0; i < n; ++i)
            if (!visited[i])
                return false;
        return true;
    }
};