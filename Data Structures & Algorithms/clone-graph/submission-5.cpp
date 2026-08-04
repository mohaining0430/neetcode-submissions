/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;
        unordered_map<Node*, Node*> m;
        queue<Node*> q;
        Node* newRoot = new Node(node->val);
        m[node] = newRoot;
        q.push(node);
        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();
            for (auto neighbor : cur->neighbors) {
                if (!m.contains(neighbor)) {
                    m[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                m[cur]->neighbors.push_back(m[neighbor]);
            }
        }
        return m[node];
    }
};
