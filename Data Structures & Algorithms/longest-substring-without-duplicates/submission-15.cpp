class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, left = 0;
        unordered_set<char> seen;

        for (int right = 0; right < s.size(); ++right) {
            if (!seen.contains(s[right])) {
                res = max(res, right - left + 1);
                seen.insert(s[right]);
            } else {
                while (s[left] != s[right]) {
                    seen.erase(s[left]);
                    left++;
                }
                left++;
            }
        }
        return res;
    }
};