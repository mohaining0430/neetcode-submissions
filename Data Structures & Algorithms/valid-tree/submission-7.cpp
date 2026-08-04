class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<vector<int>> neighbors(n);
        for (const auto& edge : edges) {
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);
        }

        queue<pair<int, int>> q;
        q.push({0, -1});
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int node = cur.first, parent = cur.second;
            visited[node] = true;
            for (auto neighbor : neighbors[node]) {
                if (neighbor == parent)
                    continue;
                if (visited[neighbor])
                    return false;
                q.push({neighbor, node});
            }
        }
        for (int i = 0; i < n; ++i)
            if (!visited[i])
                return false;
        return true;
    }
};