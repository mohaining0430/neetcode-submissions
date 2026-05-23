class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size(); // number of nodes.
        parent.resize(n + 1);
        for (int i = 1; i <= n; ++i)
            parent[i] = i;

        for (auto edge : edges) {
            int p = edge[0], q = edge[1];
            if (!unite(p, q))
                return edge;
            unite(q, q);
        }
        return vector<int>();
    }

private:
    vector<int> parent;

    int root(int i) {
        while(parent[i] != i)
            i = parent[i];
        return parent[i];
    }

    bool unite(int p, int q) {
        int i = root(p);
        int j = root(q);
        // If already connected, return false -- cycle detected.
        if (i == j)
            return false;
        parent[i] = j;
        return true;
    }
};
