class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tmap, smap;
        for (const auto c : t)
            tmap[c]++;
        int tcnt = tmap.size(), scnt = 0;
        int left = 0;
        int resLen = INT_MAX;
        string res;

        for (int right = 0; right < s.size(); ++right) {
            if (tmap.contains(s[right])) {
                smap[s[right]]++;
                if (smap[s[right]] == tmap[s[right]])
                    scnt++;
            }
            while (scnt == tcnt) {
                if (right - left + 1 < resLen) {
                    resLen = right - left + 1;
                    res = s.substr(left, right - left + 1);
                }
                if (tmap.contains(s[left])) {
                    smap[s[left]]--;
                    if (smap[s[left]] < tmap[s[left]])
                        scnt--;
                }
                left++;
            }
        }
        return res;
    }
};
