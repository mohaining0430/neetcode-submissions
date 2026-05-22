class Solution {
public:
    /*
        A common mistake is recalculating the maximum by iterating through 
        all counts after shrinking the window. In the optimal solution, you 
        do not need to decrease maxf when shrinking because keeping a stale 
        (higher) maxf only makes the window condition stricter, which is still 
        correct. However, misunderstanding this can lead to unnecessary 
        complexity or bugs.   

        (haimo) The reason is that we don't need to update maxFreq to a smaller
        value - that can only give a smaller result. When the maxFreq gets updated
        to a large value i.e., by `maxFreq = max(maxFreq, freq[s[right] - 'A']);`,
        we might have a larger result, which is what we want.
    */
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int maxf = 0;
        int res = 0, left = 0, right = 0;
        for (right = 0; right < s.size(); ++right) {
            freq[s[right]]++;
            maxf = max(maxf, freq[s[right]]);
            if (right - left + 1 - maxf <= k) {
                res = max(res, right - left + 1);
            } else {
                while (right - left + 1 - maxf > k) {
                    freq[s[left]]--;
                    left++;
                }
            }
        }
        return res;
    }
};
