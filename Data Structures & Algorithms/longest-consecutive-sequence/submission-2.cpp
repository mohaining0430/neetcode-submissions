class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> unvisited(nums.begin(), nums.end());
        int res = 0;
        for (const auto num : nums) {
            if (!unvisited.contains(num))
                continue;
            int cnt = 0;
            int cur = num;
            while (unvisited.contains(cur)) {
                unvisited.erase(cur);
                cur--;
                cnt++;
            }
            cur = num + 1;
            while (unvisited.contains(cur)) {
                unvisited.erase(cur);
                cur++;
                cnt++;
            }
            res = max(res, cnt);
        }
        return res;
    }
};
