/*Need more practice*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (const auto num : nums)
            m[num]++;
        vector<std::pair<int, int>> pairs;
        for (const auto iter : m)
            pairs.push_back({iter.first, iter.second});
        
        auto cmp = [](const pair<int, int>& p1, const pair<int, int>& p2) {return p1.second < p2.second;};   
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq;
        for (auto pair : pairs)
            pq.push(pair);
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};
