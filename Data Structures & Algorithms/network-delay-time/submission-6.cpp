class Solution {
public:
    // can use DFS instead of Dijkstra.
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        unordered_map<int, vector<pair<int, int>>> neighbors;
        for (const auto time : times) {
            neighbors[time[0]].push_back({time[1], time[2]});
        }
        int res = 0;
        dfs(neighbors, k, dist);
        for (int i = 1; i <= n; ++i)
            res = max(res, dist[i]);
        return res == INT_MAX ?  -1 : res;
    }

private:
    void dfs(unordered_map<int, vector<pair<int, int>>>& neighbors, int cur,
                vector<int>& dist) {
        for (const auto neighbor : neighbors[cur]) {
            if (dist[cur] + neighbor.second < dist[neighbor.first]) {
                dist[neighbor.first] = dist[cur] + neighbor.second;
                dfs(neighbors, neighbor.first, dist);
            }
        }
    }
};
