class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // build a map [*ag --> [bag, sag, dag]]; [ba* --> [bat, bag]]... 
        unordered_map<string, vector<string>> m;
        for (auto word : wordList) {
            for (int i = 0; i < word.size(); ++i) {
                auto pattern = word.substr(0, i) + "*" + word.substr(i + 1);
                m[pattern].push_back(word);
            }
        }

        queue<string> q;
        q.push(beginWord);
        unordered_set<string> visited;
        int level = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto cur = q.front();
                q.pop();
                if (cur == endWord)
                    return level;
                visited.insert(cur);
                for (int j = 0; j < cur.size(); ++j) {
                    auto pattern = cur.substr(0, j) + "*" + cur.substr(j + 1);
                    if (m.contains(pattern)) {
                        for (auto neighbor : m[pattern]) {
                            if (!visited.contains(neighbor)) {
                                q.push(neighbor);
                            }
                        }
                    }
                }
            }   
            level++;  
        }
        return 0;
    }
};