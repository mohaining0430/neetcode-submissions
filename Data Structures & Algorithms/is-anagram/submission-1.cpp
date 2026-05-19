class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cnt(26, 0);
        for (const auto c : s)
            cnt[c - 'a']++;
        for (const auto c : t) {
            if (cnt[c - 'a'] == 0)
                return false;
            cnt[c - 'a']--;
        }
        for (const auto count : cnt) {
            if (count > 0)
                return false;
        }
        return true;
    }
};
