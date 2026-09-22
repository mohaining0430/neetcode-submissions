class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        root.resize(n);
        for (int i= 0; i < n; ++i)
            root[i] = i;
        
        for (auto edge : edges) {
            unite(edge[0], edge[1]);
        }
        set<int> roots;
        for (int i = 0; i < n; ++i)
            roots.insert(find(i));
        return roots.size();
    }

private:
    vector<int> root;

    int find(int node) {
        if (root[node] == node)
            return node;
        return find(root[node]);
    }

    bool unite(int p, int q) {
        int p1 = find(p), p2 = find(q);
        if (p1 == p2)
            return false;
        root[p2] = p1;
        return true;
    }
};