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
        if (n == 1) 
            return {0};
        vector<unordered_set<int>> neighbors(n);
        for (const auto& edge : edges) {
            neighbors[edge[0]].insert(edge[1]);
            neighbors[edge[1]].insert(edge[0]);
        }        

        vector<int> res;
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (neighbors[i].size() == 1)
                q.push(i);
        
        while (!q.empty()) {
            res.clear();
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int cur = q.front();
                res.push_back(cur);
                q.pop();
                for (auto neighbor : neighbors[cur]) {
                    neighbors[neighbor].erase(cur);
                    if (neighbors[neighbor].size() == 1)
                        q.push(neighbor);
                }
            }
        }
        return res;
    }
};