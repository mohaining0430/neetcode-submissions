class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // build a map [*ag --> [bag, sag, dag]]; [ba* --> [bat, bag]]... 
        unordered_map<string, vector<string>> dict;
        for (auto word : wordList) {
            for (int i = 0; i < word.size(); ++i) {
                string pattern = word.substr(0, i) + "*" + word.substr(i + 1);
                dict[pattern].push_back(word);
            }
        }

        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);

        int res = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                string cur = q.front();
                q.pop();
                if (cur == endWord)
                    return res;
                for (int j = 0; j < cur.size(); ++j) {
                    string pattern = cur.substr(0, j) + "*" + cur.substr(j + 1);
                    for (auto next : dict[pattern]) {
                        if (!visited.contains(next)) {
                            q.push(next);
                            visited.insert(next);
                        }
                    }
                }
            }
            res++;
        }
        return 0;
    }
};