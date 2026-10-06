class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> neighbors;
        for (const auto& edge : edges) {
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> visited;
        queue<pair<int, int>> q;
        q.push({0, -1});
        visited.insert(0);
        
        while (!q.empty()) {
            int cur = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (const auto neighbor : neighbors[cur]) {
                if (neighbor == parent)
                    continue;
                if (visited.contains(neighbor))
                    return false;
                visited.insert(neighbor);
                q.push({neighbor, cur});
            }
        }

        return visited.size() == n;
    }
};