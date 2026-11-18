class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> neighbors(n);
        for (const auto edge : edges) {
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> visited;
        queue<pair<int, int>> q;
        q.push({0, -1});
        visited.insert(0);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int cur = q.front().first, parent = q.front().second;
                q.pop();
                for (const auto neighbor : neighbors[cur]) {
                    if (neighbor == parent)
                        continue;
                    if (visited.contains(neighbor))
                        return false;
                    q.push({neighbor, cur});
                    visited.insert(neighbor);
                }
            }
        }

        return visited.size() == n;
    }
};