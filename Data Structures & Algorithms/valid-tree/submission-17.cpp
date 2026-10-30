class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> neighbors(n);
        for (const auto edge : edges) {
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);
        }
        queue<pair<int, int>> q;
        vector<bool> visited(n);
        q.push({0, -1});
        visited[0] = true;
        while (!q.empty()) {
            int cur = q.front().first, parent = q.front().second;
            q.pop();
            for (auto neighbor : neighbors[cur]) {
                if (neighbor == parent)
                    continue;
                if (visited[neighbor])
                    return false;
                visited[neighbor] = true;
                q.push({neighbor, cur});
            }
        }
        for (const auto v : visited)
            if (!v)
                return false;
        return true;
    }
};