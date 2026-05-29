class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int left = 0, right = 0;
        unordered_set<char> seen;
        for (right = 0; right < s.size(); ++right) {
            if (!seen.contains(s[right])) {
                seen.insert(s[right]);
            } else {
                while (s[left] != s[right]) {
                    seen.erase(s[left]);
                    left++;
                }
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};