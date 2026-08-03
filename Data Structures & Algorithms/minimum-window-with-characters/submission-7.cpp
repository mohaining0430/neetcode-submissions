class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> smap, tmap;
        for (const auto c: t)
            tmap[c]++;
        int scnt = 0, tcnt = tmap.size();
        int left = 0, right = 0, resLen = INT_MAX;

        if (s.empty()) return "";
        
        string res = "";
        for (right = 0; right < s.length(); right++) {
            smap[s[right]]++;
            if (smap[s[right]] == tmap[s[right]])
                scnt++;
            // The while loop finds the first left that does NOT meet the condition, because
            // the for loop finds the first right that meets the condition.

            // Compare with "Longest repeating character replacment", where the while loop 
            // finds the first left that meets the condition, because that for loop finds
            // the first right that does NOT meet the condition.
            while (scnt == tcnt) {
                if (right - left + 1 < resLen) {
                    resLen = right - left + 1;
                    res = s.substr(left, resLen);
                }
                smap[s[left]]--;
                if (tmap.contains(s[left]) && smap[s[left]] < tmap[s[left]])
                    scnt--;
                left++;
            }
        }

        return res;
    }
};
