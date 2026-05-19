class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        for (const auto num : nums)
            um[num]++;

        map<int, vector<int>, std::greater<int>> m;
        for (const auto iter : um) 
            m[iter.second].push_back(iter.first);

        vector<int> res;
        for (const auto iter : m) {
            if (k <= 0) {
                break;
            } else {
                int cnt = k < iter.second.size() ? k : iter.second.size();
                res.insert(res.end(), iter.second.begin(), iter.second.begin() + cnt);
                k -= cnt;
            }
        }
        return res;
    }
};
