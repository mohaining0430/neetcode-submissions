class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        parents.resize(n);
        for (int i = 0; i < n; ++i)
            parents[i] = i;

        for (const auto& edge : edges)
            unify(edge[0], edge[1]);

        unordered_set<int> roots;
        for (int i = 0; i < n; ++i)
            roots.insert(root(i));

        return roots.size();
    }

private:
    int root(int node) {
        while (node != parents[node])
            node = parents[node];
        return node;
    }

    bool unify(int i, int j) {
        int p = root(i), q = root(j);
        if (p == q)
            return false;
        parents[p] = q;
        return true;
    }

    vector<int> parents;
};
