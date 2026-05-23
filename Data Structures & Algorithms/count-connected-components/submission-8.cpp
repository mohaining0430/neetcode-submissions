class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i;

        for (auto edge : edges)
            unite(edge[0], edge[1]);

        set<int> roots;
        for (int i = 0; i < n; ++i)
            roots.insert(root(i));
        return roots.size();
    }

private:
    // Define parent here and resize in countComponents(), so that we
    // don't have to add parent input argument to root() and unite().
    vector<int> parent;

    int root(int i) {
        while(parent[i] != i)
            i = parent[i];
        return parent[i];
    }

    void unite(int p, int q) {
        int i = root(p);
        int j = root(q);
        parent[i] = j;
    }
};
