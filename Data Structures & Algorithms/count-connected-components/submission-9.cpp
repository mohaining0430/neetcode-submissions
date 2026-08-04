class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        parents = vector<int>(n, -1);
        for (int i = 0; i < n; ++i)
            parents[i] = i;
        for (auto edge : edges)
            unite(edge[0], edge[1]);
        unordered_set<int> roots;
        for (int i = 0; i < n; ++i)
            roots.insert(find(i));
        return roots.size();
    }

private:
    int find(int node) {
        if (parents[node] == node)
            return node;
        return find(parents[node]);
    }

    bool unite(int i, int j) {
        int p = find(i), q = find(j);
        if (p == q)
            return false;
        parents[p] = q;
        return true;
    }

    vector<int> parents;
};
