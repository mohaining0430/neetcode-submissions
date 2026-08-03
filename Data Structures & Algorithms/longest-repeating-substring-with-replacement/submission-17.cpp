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
        int res = 0, left = 0, maxFreq = 0;
        unordered_map<char, int> m;
        for (int right = 0; right < s.size(); ++right) {
            m[s[right]]++;
            maxFreq = max(m[s[right]], maxFreq);
            while (right - left + 1 - maxFreq > k) {
                m[s[left]]--;
                left++;            
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
