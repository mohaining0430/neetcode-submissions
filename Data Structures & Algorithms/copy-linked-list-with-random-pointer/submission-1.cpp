/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;

        unordered_map<Node*, Node*> m;
        m[head] = new Node(head->val);
        Node *cur = head;
        while (cur != nullptr) {
            if (cur->next != nullptr) {
                if (m.find(cur->next) == m.end()) {
                    m[cur->next] = new Node(cur->next->val);
                }
                m[cur]->next = m[cur->next];
            }
            if (cur->random != nullptr) {
                if (m.find(cur->random) == m.end()) {
                    m[cur->random] = new Node(cur->random->val);
                }
                m[cur]->random = m[cur->random];  
            }    
            cur = cur->next;      
        }
        return m[head];
    }
};
