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
        unordered_map<Node*, Node*> m;
        queue<Node*> q;
        if (node == nullptr)
            return nullptr;
        m[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                Node *cur = q.front();
                q.pop();
                for (auto neighbor : cur->neighbors) {
                    if (!m.contains(neighbor)) {
                        m[neighbor] = new Node(neighbor->val);
                        // You want to push the neighbor to queue only if the neighbor is 
                        // newly created; Otherwise, you push 1 back to queue again, when 
                        // you go through 2's neighbors.
                        q.push(neighbor);
                    }
                    m[cur]->neighbors.push_back(m[neighbor]);
                }
            }
        }

        return m[node];
    }
};
