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

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *cur = root;
        for (const auto c : word) {
            if (cur->children[c - 'a'] == nullptr)
                cur->children[c - 'a'] = new TrieNode();
            cur = cur->children[c - 'a'];
        }
        cur->isWord = true;      
    }
    
    bool search(string word) {
       return dfs(word, 0, root);
    }

    bool dfs(string word, int index, TrieNode* cur) {
        if (index == word.size()) {
            return cur->isWord;
        }

        auto c = word[index];
        if (c != '.') {
            if (cur->children[c - 'a'] == nullptr)
                return false;
            cur = cur->children[c - 'a'];
            return dfs(word, index + 1, cur);
        } else {
            for (int i = 0; i < 26; ++i) {
                if (cur->children[i] != nullptr && dfs(word, index + 1, cur->children[i]))
                    return true;
            }
            return false;
        }
    }

private:
    TrieNode *root;
};
