class Solution {
public:
    // can use DFS instead of Dijkstra.
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> neighbors(n + 1);
        for (const auto time : times) {
            neighbors[time[0]].push_back({time[1], time[2]});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        dfs(neighbors, dist, k);

        int res = 0;
        for (int i = 1; i <= n; ++i)
            res = max(res, dist[i]);
        return res == INT_MAX ? -1 : res;
    }

private:
    void dfs(vector<vector<pair<int, int>>>& neighbors, vector<int>& dist, int cur) {
        for (const auto& neighbor : neighbors[cur]) {
            if (dist[cur] + neighbor.second < dist[neighbor.first]) {
                dist[neighbor.first] = dist[cur] + neighbor.second;
                dfs(neighbors, dist, neighbor.first);
            }
        }
    }
};
