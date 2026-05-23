class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> dict;
        for (const auto word : wordList) {
            for (int i = 0; i < word.size(); ++i) {
                auto pattern = word.substr(0, i) + "*" + word.substr(i + 1);
                dict[pattern].push_back(word);
            }
        }

        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        int res = 1;
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto word = q.front();
                q.pop();
                if (word == endWord)
                    return res;
                visited.insert(word);
                for (int i = 0; i < word.size(); ++i) {
                    auto pattern = word.substr(0, i) + "*" + word.substr(i + 1);
                    for (const auto neighbor : dict[pattern]) {
                        if (!visited.contains(neighbor)) 
                            q.push(neighbor);
                    }
                }
            }
            res++;
        }
        return 0;
    }
};