class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
        for (const auto edge : edges) {
            unite(edge[0], edge[1]);
        }
        unordered_set<int> parents;
        for (int i = 0; i < n; ++i)
            parents.insert(find(i));
        return parents.size();
    }

private:
    // Define parent here and resize in countComponents(), so that we
    // don't have to add parent input argument to root() and unite().
    vector<int> parent;

    int find(int node) {
        if (parent[node] == node)
            return node;
        return find(parent[node]);
    }

    void unite(int p, int q) {
        int p1 = find(p), p2 = find(q);
        if (p1 != p2)
            parent[p1] = p2;
    }
};