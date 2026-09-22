class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;
    TrieNode() {
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
        isWord = false;
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for (auto c : word) {
            if (cur->children[c - 'a'] == nullptr)
                cur->children[c - 'a'] = new TrieNode();
            cur = cur->children[c - 'a'];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        return dfs(root, word, 0);
    }  

    bool dfs(TrieNode* cur, string word, int index) {
        if (index == word.size())
            return cur->isWord;
        auto c = word[index];
        if (c != '.') {
            if (cur->children[c - 'a'] == nullptr)
                return false;
            return dfs(cur->children[c - 'a'], word, index + 1);
        } else {
            for (int i = 0; i < 26; ++i)
                if (cur->children[i] != nullptr && dfs(cur->children[i], word, index + 1))
                    return true;
            return false;
        }
    }

private:
    TrieNode* root;
};