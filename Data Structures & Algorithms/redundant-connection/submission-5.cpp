class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parents.resize(n + 1);
        for (int i = 1; i <= n; ++i)
            parents[i] = i;

        for (const auto edge : edges) {
            if (!unite(edge[0], edge[1])) 
                return edge;
        }
        
        vector<int> res;
        return res;
    }

private:
    vector<int> parents;

    int find(int node) {
        while (parents[node] != node)
            node = parents[node];
        return node;
    }

    bool unite(int p, int q) {
        int p1 = find(p), p2 = find(q);
        if (p1 == p2)
            return false;
        parents[p1] = p2;
        return true;
    }
};
