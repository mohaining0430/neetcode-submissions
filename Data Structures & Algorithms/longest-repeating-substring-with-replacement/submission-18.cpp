class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freqs;
        int maxf = 0, left = 0, right = 0, res = 0;
        for (right = 0; right < s.size(); ++right) {
            freqs[s[right]]++;
            maxf = max(maxf, freqs[s[right]]);
            while (right - left + 1 - maxf > k) {
                freqs[s[left]]--;
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
