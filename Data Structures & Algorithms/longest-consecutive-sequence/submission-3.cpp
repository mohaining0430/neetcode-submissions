class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int res = 0;
        for (const auto num : nums)
            s.insert(num);
        for (const auto num : nums) {
            if (!s.contains(num))
                continue;
            int cnt = 0;
            int cur = num;
            while (s.contains(cur)) {
                cnt++;
                s.erase(cur);
                cur--;
            }
            cur = num + 1;
            while (s.contains(cur)) {
                cnt++;
                s.erase(cur);
                cur++;
            }        
            res = max(res, cnt);    
        }
        return res;
    }
};
