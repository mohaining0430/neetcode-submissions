class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        cap = capacity;
    }
    
    int get(int key) {
        if (!cache.contains(key))
            return -1;
        int val = cache[key]->val;
        removeNode(key);
        appendNode(key, val);
        return val;
    }
    
    void put(int key, int val) {
        if (cache.contains(key)) {
            removeNode(key);
            appendNode(key, val);
        } else {
            appendNode(key, val);
            if (cache.size() > cap)
                removeNode(head->next->key);
        }
    }

private:
    Node* head;
    Node* tail;
    unordered_map<int, Node*> cache;
    int cap;

    void removeNode(int key) {
        Node* node = cache[key];
        node->prev->next = node->next;
        node->next->prev = node->prev;
        cache.erase(key);
    }

    void appendNode(int key, int val) {
        Node* node = new Node(key, val);
        tail->prev->next = node;
        node->prev = tail->prev;
        tail->prev = node;
        node->next = tail;
        cache[key] = node;
    }
};
