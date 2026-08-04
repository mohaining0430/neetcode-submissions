class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n);
        vector<vector<int>> neighbors(n);
        for (const auto& edge : edges) {
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);
        }

        // You need to verify two things: 1) all nodes visited; 2) no cycle
        queue<pair<int, int>> q;
        q.push({0, -1});
        while (!q.empty()) {
            int cur = q.front().first;
            visited[cur] = true;
            int parent = q.front().second;
            q.pop();
            for (const auto neighbor : neighbors[cur]) {
                if (neighbor == parent)
                    continue;
                if (visited[neighbor])
                    return false;
                q.push({neighbor, cur});
            }
        }

        for (const auto v : visited)
            if (!v)
                return false;
        return true;
    }
};

/*
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_set<int> visited;
        unordered_map<int, vector<int>> neighbors;
        for (const auto edge : edges) {
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);
        }

        // You need to verify two things: 1) all nodes visited; 2) no cycle
        queue<std::pair<int, int>> q;
        q.push({0, -1});
        while (!q.empty()) {
            int cur = q.front().first;
            visited.insert(cur);
            int parent = q.front().second;
            q.pop();
            for (const auto neighbor : neighbors[cur]) {
                if (neighbor == parent)
                    continue;
                if (visited.contains(neighbor))
                    return false;
                q.push({neighbor, cur});
            }
        }

        return visited.size() == n;
    }
};
*/