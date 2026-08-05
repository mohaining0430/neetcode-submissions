class TrieNode {
public:
    TrieNode() {
        isWord = false;
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
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
        TrieNode* cur = root;
        for (auto c : word) {
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
        if (index == word.size())
            return cur->isWord;
        if (word[index] != '.') {
            if (cur->children[word[index] - 'a'] == nullptr)
                return false;
            return dfs(word, index + 1, cur->children[word[index] - 'a']);
        } else {
            for (auto child : cur->children) {
                if (child != nullptr) {
                    if (dfs(word, index + 1, child))
                        return true;
                }
            }
            return false;
        }
        return false;
    }

private:
    TrieNode *root;
};
