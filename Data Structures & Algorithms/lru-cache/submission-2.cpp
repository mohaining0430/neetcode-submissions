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
        if (cache.find(key) == cache.end())
            return -1;
        int val = cache[key]->val;
        removeFromList(key);
        appendToList(key, val);
        return val;
    }
    
    void put(int key, int value) {
        if (cache.find(key) == cache.end()) {
            appendToList(key, value);
            if (cache.size() > cap) {
                removeFromList(head->next->key);
            }
        } else {
            removeFromList(key);
            appendToList(key, value);
        }
    }

private:
    Node *head;
    Node *tail;
    unordered_map<int, Node*> cache;
    int cap;

    void appendToList(int key, int val) {
        Node *node = new Node(key, val);
        tail->prev->next = node;
        node->prev = tail->prev;
        node->next = tail;
        tail->prev = node;
        cache[key] = node;
    }

    void removeFromList(int key) {
        if (cache.find(key) == cache.end())
            return;
        Node *node = cache[key];
        node->prev->next = node->next;
        node->next->prev = node->prev;
        cache.erase(key);
    }
};
