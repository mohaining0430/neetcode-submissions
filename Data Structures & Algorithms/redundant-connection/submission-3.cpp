class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 2);
        for (int i = 1; i <= n + 1; ++i)
            parent[i] = i;
        for (auto edge : edges) {
            if (!unite(edge[0], edge[1]))
                return edge;
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
