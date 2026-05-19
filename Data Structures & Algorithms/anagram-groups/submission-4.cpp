/*** More practice ***/
class Solution {
public:
    struct ArrayHasher {
        size_t operator() (const array<int, 26>& array) const {
            size_t h = 0;
            for (auto i : array) {
                h ^= std::hash<int>{}(i) + 0xeb907b63 + h << 6 + h >> 2;
            }
            return h;
        }
    };

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<array<int, 26>> freq(strs.size());
        for (int i = 0; i < strs.size(); ++i) {
            for (const auto c : strs[i]) {
                freq[i][c - 'a']++;
            }
        }

        unordered_map<array<int, 26>, vector<string>, ArrayHasher> m;
        for (int i = 0; i < strs.size(); ++i) {
            m[freq[i]].push_back(strs[i]);
        }

        vector<vector<string>> res;
        for (auto iter : m)
            res.push_back(iter.second);

        return res;
    }
};
