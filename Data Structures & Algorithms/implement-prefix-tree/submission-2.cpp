class TrieNode {
public:
    TrieNode() {
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
        isWord = false;
    }

    TrieNode* children[26];
    bool isWord;
};

class PrefixTree {
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *cur = root;
        for (const auto c : word) {
            if (cur->children[c - 'a'] == nullptr)
                cur->children[c - 'a'] = new TrieNode();
            cur = cur->children[c - 'a'];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        TrieNode *cur = root;
        for (const auto c : word) {
            if (cur->children[c - 'a'] == nullptr)
                return false;
            cur = cur->children[c - 'a'];
        }
        return cur->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for (const auto c : prefix) {
            if (cur->children[c - 'a'] == nullptr)
                return false;
            cur = cur->children[c - 'a'];
        }    
        return true;
    }

private:
    TrieNode *root;
};
