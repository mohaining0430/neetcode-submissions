class Solution {
public:
/*
    Result will be either one node or two nodes:
      1\ /5                  1\ /4
        2                      2 
        |                    3/ \5
        3
      4/ \6
*/
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> res;
        if (n == 1) {
            res.push_back(0);
            return res;
        }
        unordered_map<int, unordered_set<int>> neighbors;
        queue<int> q;
        for (const auto edge : edges) {
            neighbors[edge[0]].insert(edge[1]);
            neighbors[edge[1]].insert(edge[0]);
        }
        for (int node = 0; node < n; ++node)
            if (neighbors[node].size() == 1)
                q.push(node);
        while (!q.empty()) {
            res.clear();
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int cur = q.front();
                q.pop();
                res.push_back(cur);
                for (const auto neighbor : neighbors[cur]) {
                    neighbors[neighbor].erase(cur);
                    if (neighbors[neighbor].size() == 1)
                        q.push(neighbor);
                }
            }
        }
        return res;
    }
};