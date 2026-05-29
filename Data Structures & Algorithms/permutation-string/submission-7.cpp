class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        auto& s = s2, &t = s1;
        unordered_map<char, int> smap, tmap;
        int scnt = 0, tcnt = 0;
        int res = INT_MAX;
        int left = 0, right = 0;

        for (const auto c : t)
            tmap[c]++;
        tcnt = tmap.size();

        for (right = 0; right < s.size(); ++right) {
            smap[s[right]]++;
            if (tmap.contains(s[right]) && smap[s[right]] == tmap[s[right]])
                scnt++;
            while (scnt == tcnt) {
                res = min(res, right - left + 1);
                if (res == t.size())
                    return true;
                smap[s[left]]--;
                if (tmap.contains(s[left]) && smap[s[left]] < tmap[s[left]])
                    scnt--;
                left++;
            }
        }

        return false;
    }
};
