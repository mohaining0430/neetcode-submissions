class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (auto num : nums)
            s.insert(num);
        int res = 0;
        for (auto num : nums) {
            if (!s.contains(num))
                continue;
            int len = 0;
            int tmp = num;
            while (s.contains(tmp)) {
                s.erase(tmp);
                len++;
                tmp++;
            }
            tmp = num - 1;
            while (s.contains(tmp)) {
                s.erase(tmp);
                len++;
                tmp--;
            }         
            res = max(res, len);   
        }
        return res;
    }
};
